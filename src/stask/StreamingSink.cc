#include "StreamingSink.h"

namespace ecsnetpp
{

    Define_Module(StreamingSink);

    void StreamingSink::initialize()
    {
        omnetpp::cModule *submodule = getParentModule()->getSubmodule("cpuCoreScheduler");
        myCpuCoreScheduler = check_and_cast<ICpuCoreScheduler *>(submodule);
        ackersEnabled = getAncestorPar("ackersEnabled").boolValue();
        perCoreFreq = getAncestorPar("perCoreFreq").doubleValue();
        //    if (isProcessingDelayInCpuCycles) {
        //        cyclesPerEvent = par("cyclesPerEvent").doubleValue();
        //    } else {
        processingDelayPerEvent = par("processingDelayPerEvent").doubleValue();
        //    }
        mySenders = par("mySenders").stringValue();
        mySTaskCategory = par("mySTaskCategory").stringValue();
        lastCPUIndex = 0;
        cpuCores = getAncestorPar("cores").longValue();
        if (cpuCores < 1)
        {
            throw new cRuntimeError("Number of CPU Cores is not set.");
        }
        //    calculateDelay();
    }

    void StreamingSink::handleMessage(cMessage *msg)
    {
        if (msg->arrivedOn("fromCPU"))
        {
            StreamingMessage *pk = check_and_cast<StreamingMessage *>(msg);
            double _networkDelay = pk->getNetworkDelay();
            double _processingDelay = pk->getProcessingDelay();
            emit(transmissionTimeSignal, _networkDelay);
            emit(processingTimeSignal, _processingDelay);
            //        const omnetpp::SimTime _latency = simTime() - pk->getStartTime();
            emit(latencySignal, _networkDelay + _processingDelay);
            emit(edgeProcessingTimeSignal, pk->getEdgeProcessingDelay());
            emit(receivedStreamingMsgsSignal, pk);
            //        std::cout << " CPU proc delay: " << pk->getEdgeProcessingDelay() << " : " <<  pk->getProcessingDelay() << endl;
            //        std::cout << "##Finished Processing. Msg size (Bytes): " << pk->getByteLength() << " (Bits): " << pk->getBitLength() << endl;

            //        sendAck(msg);
            delete msg;
        }
        else if (msg->arrivedOn("incomingStream"))
        {
            StreamingMessage *msgToSend = check_and_cast<StreamingMessage *>(msg);
            msgToSend->setSender(mySTaskCategory);

            msgToSend->setIsProcessingDelayInCyclesPerEvent(isProcessingDelayInCpuCycles);
            msgToSend->setProcessingDelayPerEvent(processingDelayPerEvent);

            msgToSend->setSelectivityRatio(1);
            long nextInLine = getNextProcessorCoreIndex();
            cModule *cpuCore = getParentModule()->getSubmodule("cpuCore", nextInLine);
            sendDirect(msgToSend, cpuCore, "incomingBus");
        }
        //    StreamingMessage *pk = check_and_cast<StreamingMessage *>(msg);
        //    const char* sender = pk->getSender();
        //    if (strstr(mySenders, sender) == NULL) {
        //        delete msg;
        //    } else {
        //        publishCpuStateChanged(States::CPU_BUSY);
        //        emit(rcvdPkSignal, pk);
        //        sendAck(msg);
        //        delete msg;
        //
        //        publishCpuStateChanged(States::CPU_IDLE);
        //    }
    }
} /* namespace ecsnetpp */
