#ifndef STASK_ISTASK_H_
#define STASK_ISTASK_H_

#include "omnetpp.h"
#include "../msg/StreamingMessage_m.h"
#include "../msg/Ack_m.h"
#include "../power/States.h"
#include "../cpu/scheduling/ICpuCoreScheduler.h"

using namespace omnetpp;

namespace ecsnetpp
{

    class ISTask : public cSimpleModule
    {
    public:
        static simsignal_t receivedStreamingMsgsSignal;
        static simsignal_t cpuUtilisationSignal;
        static simsignal_t cpuStateChangedSignal;
        static simsignal_t packetGeneratedSignal;
        static simsignal_t latencySignal;
        static simsignal_t transmissionTimeSignal;
        static simsignal_t processingTimeSignal;
        static simsignal_t edgeProcessingTimeSignal;

    protected:
        const char *mySenders;
        const char *mySTaskCategory;
        std::vector<std::string> mySendersList;
        long cpuCores;
        long lastCPUIndex = 0;
        double perCoreFreq;
        double processingDelayPerEvent;
        double delay;
        bool ackersEnabled;
        bool isProcessingDelayInCpuCycles;
        ICpuCoreScheduler *myCpuCoreScheduler;

    protected:
        virtual void initialize(){};
        virtual void handleMessage(cMessage *msg){};
        virtual long getNextProcessorCoreIndex();
        virtual void sendAck(cMessage *msg);
        virtual void publishCpuStateChanged(States::CPUState state);
    };

} /* namespace ecsnetpp */

#endif /* STASK_ISTASK_H_ */
