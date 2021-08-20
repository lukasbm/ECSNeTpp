#include "NetworkPowerConsumer.h"

#include "inet/common/ModuleAccess.h"
#include "../../stask/ISTask.h"

namespace ecsnetpp
{

    simsignal_t NetworkPowerConsumer::networkPowerConsumptionChangedSignal = registerSignal("networkPowerConsumptionChanged");

    Define_Module(NetworkPowerConsumer);

    void NetworkPowerConsumer::initialize(int stage)
    {
        cSimpleModule::initialize(stage);
        if (stage == inet::INITSTAGE_LOCAL)
        {
            offPowerConsumption = W(par("offPowerConsumption"));
            sleepPowerConsumption = W(par("sleepPowerConsumption"));
            switchingPowerConsumption = W(par("switchingPowerConsumption"));
            receiverIdlePowerConsumption = W(par("receiverIdlePowerConsumption"));
            receiverBusyPowerConsumption = W(par("receiverBusyPowerConsumption"));
            receiverReceivingPowerConsumption = W(
                par("receiverReceivingPowerConsumption"));
            receiverReceivingPreamblePowerConsumption = W(
                par("receiverReceivingPreamblePowerConsumption"));
            receiverReceivingHeaderPowerConsumption = W(
                par("receiverReceivingHeaderPowerConsumption"));
            receiverReceivingDataPowerConsumption = W(
                par("receiverReceivingDataPowerConsumption"));
            transmitterIdlePowerConsumption = W(
                par("transmitterIdlePowerConsumption"));
            transmitterTransmittingPowerConsumption = W(
                par("transmitterTransmittingPowerConsumption"));
            transmitterTransmittingPreamblePowerConsumption = W(
                par("transmitterTransmittingPreamblePowerConsumption"));
            transmitterTransmittingHeaderPowerConsumption = W(
                par("transmitterTransmittingHeaderPowerConsumption"));
            transmitterTransmittingDataPowerConsumption = W(
                par("transmitterTransmittingDataPowerConsumption"));
            cpuPowerConsumptionScalar =
                par("cpuPowerConsumptionScalar").doubleValue();
            cModule *parent = getParentModule();
            parent->subscribe(IRadio::radioModeChangedSignal, this);
            parent->subscribe(IRadio::receptionStateChangedSignal, this);
            parent->subscribe(IRadio::transmissionStateChangedSignal, this);
            parent->subscribe(IRadio::receivedSignalPartChangedSignal, this);
            parent->subscribe(IRadio::transmittedSignalPartChangedSignal,
                              this);

            cModule *radioModule = parent->getSubmodule("wlan", 0)->getSubmodule("radio");
            radio = check_and_cast<IRadio *>(radioModule);
            powerConsumption = W(0);
            WATCH(powerConsumption);
        }
    }

    W NetworkPowerConsumer::computePowerConsumption() const
    {
        IRadio::RadioMode radioMode = radio->getRadioMode();
        if (radioMode == IRadio::RADIO_MODE_OFF)
            return offPowerConsumption;
        else if (radioMode == IRadio::RADIO_MODE_SLEEP)
            return sleepPowerConsumption;
        else if (radioMode == IRadio::RADIO_MODE_SWITCHING)
            return switchingPowerConsumption;
        W _powerConsumption = W(0);
        IRadio::ReceptionState receptionState = radio->getReceptionState();
        IRadio::TransmissionState transmissionState = radio->getTransmissionState();
        if (radioMode == IRadio::RADIO_MODE_RECEIVER || radioMode == IRadio::RADIO_MODE_TRANSCEIVER)
        {
            //        std::cout << "RCV "  << _powerConsumption << endl;
            if (receptionState == IRadio::RECEPTION_STATE_IDLE)
            {
                _powerConsumption += receiverIdlePowerConsumption;
                //            std::cout << "RCV receiverIdlePowerConsumption "  << _powerConsumption << endl;
            }
            else if (receptionState == IRadio::RECEPTION_STATE_BUSY)
            {
                _powerConsumption += receiverBusyPowerConsumption;
                //            std::cout << "RCV receiverBusyPowerConsumption "  << _powerConsumption << endl;
            }
            else if (receptionState == IRadio::RECEPTION_STATE_RECEIVING)
            {
                auto part = radio->getReceivedSignalPart();
                if (part == IRadioSignal::SIGNAL_PART_NONE)
                    ;
                else if (part == IRadioSignal::SIGNAL_PART_WHOLE)
                {
                    _powerConsumption += receiverReceivingPowerConsumption;
                    //                std::cout << "RCV receiverReceivingPowerConsumption "  << _powerConsumption << endl;
                }
                else if (part == IRadioSignal::SIGNAL_PART_PREAMBLE)
                {
                    _powerConsumption += receiverReceivingPreamblePowerConsumption;
                    //                std::cout << "RCV receiverReceivingPreamblePowerConsumption "  << _powerConsumption << endl;
                }
                else if (part == IRadioSignal::SIGNAL_PART_HEADER)
                {
                    _powerConsumption += receiverReceivingHeaderPowerConsumption;
                    //                std::cout << "RCV receiverReceivingHeaderPowerConsumption "  << _powerConsumption << endl;
                }
                else if (part == IRadioSignal::SIGNAL_PART_DATA)
                {
                    _powerConsumption += receiverReceivingDataPowerConsumption;
                    //                std::cout << "RCV receiverReceivingDataPowerConsumption "  << _powerConsumption << endl;
                }
                else
                {
                    throw cRuntimeError("Unknown received signal part");
                    //                std::cout << "RCV unknown "  << _powerConsumption << endl;
                }
            }
            else if (receptionState != IRadio::RECEPTION_STATE_UNDEFINED)
                throw cRuntimeError("Unknown radio reception state");
        }
        if (radioMode == IRadio::RADIO_MODE_TRANSMITTER || radioMode == IRadio::RADIO_MODE_TRANSCEIVER)
        {
            //        std::cout << "TRS " << _powerConsumption << endl;
            if (transmissionState == IRadio::TRANSMISSION_STATE_IDLE)
            {
                _powerConsumption += transmitterIdlePowerConsumption;
                //            std::cout << "TRS transmitterIdlePowerConsumption " << _powerConsumption << endl;
            }
            else if (transmissionState == IRadio::TRANSMISSION_STATE_TRANSMITTING)
            {
                // TODO: add transmission power?
                auto part = radio->getTransmittedSignalPart();
                if (part == IRadioSignal::SIGNAL_PART_NONE)
                    ;
                else if (part == IRadioSignal::SIGNAL_PART_WHOLE)
                {
                    _powerConsumption += transmitterTransmittingPowerConsumption;
                    //                std::cout << "TRS transmitterTransmittingPowerConsumption " << _powerConsumption << endl;
                }
                else if (part == IRadioSignal::SIGNAL_PART_PREAMBLE)
                {
                    _powerConsumption += transmitterTransmittingPreamblePowerConsumption;
                    //                std::cout << "TRS transmitterTransmittingPreamblePowerConsumption " << _powerConsumption << endl;
                }
                else if (part == IRadioSignal::SIGNAL_PART_HEADER)
                {
                    _powerConsumption += transmitterTransmittingHeaderPowerConsumption;
                    //                std::cout << "TRS transmitterTransmittingHeaderPowerConsumption " << _powerConsumption << endl;
                }
                else if (part == IRadioSignal::SIGNAL_PART_DATA)
                {
                    _powerConsumption += transmitterTransmittingDataPowerConsumption;
                    //                std::cout << "TRS transmitterTransmittingDataPowerConsumption " << _powerConsumption << endl;
                }
                else
                {
                    throw cRuntimeError("Unknown transmitted signal part");
                    //                std::cout << "TRS unknown " << _powerConsumption << endl;
                }
            }
            else if (transmissionState != IRadio::TRANSMISSION_STATE_UNDEFINED)
                throw cRuntimeError("Unknown radio transmission state");
        }
        //    std::cout << "Network Power consumption=" << _powerConsumption << endl;
        return _powerConsumption;
    }

    void NetworkPowerConsumer::receiveSignal(cComponent *source,
                                             simsignal_t signal, long value, cObject *details)
    {

        if (simTime() >= getSimulation()->getWarmupPeriod())
        {
            if (signal == IRadio::radioModeChangedSignal || signal == IRadio::receptionStateChangedSignal || signal == IRadio::transmissionStateChangedSignal || signal == IRadio::receivedSignalPartChangedSignal || signal == IRadio::transmittedSignalPartChangedSignal)
            {
                powerConsumption = computePowerConsumption();
                emit(networkPowerConsumptionChangedSignal, powerConsumption.get());
            }
            else
                throw cRuntimeError("Unknown signal");
        }
    }

} /* namespace ecsnetpp */
