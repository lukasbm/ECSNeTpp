#include "ISTask.h"

namespace ecsnetpp
{

    simsignal_t ISTask::receivedStreamingMsgsSignal = registerSignal("receivedStreamingMsgs");
    simsignal_t ISTask::cpuUtilisationSignal = registerSignal("cpuUtilisationSignal");
    simsignal_t ISTask::cpuStateChangedSignal = registerSignal("cpuStateChanged");
    simsignal_t ISTask::latencySignal = registerSignal("latency");
    simsignal_t ISTask::transmissionTimeSignal = registerSignal("transmissionTime");
    simsignal_t ISTask::processingTimeSignal = registerSignal("processingTime");
    simsignal_t ISTask::edgeProcessingTimeSignal = registerSignal("edgeProcessingTime");

    void ISTask::sendAck(cMessage *msg)
    {
        //     send ack
        if (ackersEnabled)
        {
            Ack *ack = new Ack();
            ack->setAckedMessageId(msg->getId());
            ack->setSender(getFullPath().c_str());
            send(ack, "ackerOut");
        }
    }

    void ISTask::publishCpuStateChanged(States::CPUState state)
    {
        emit(cpuStateChangedSignal, state);
    }

    long ISTask::getNextProcessorCoreIndex()
    {
        return myCpuCoreScheduler->getNextCPUCoreIndex();
    }

} /* namespace ecsnetpp */
