#ifndef CPU_CPUCORE_H_
#define CPU_CPUCORE_H_

#include "omnetpp.h"
#include "../msg/StreamingMessage_m.h"

using namespace omnetpp;

namespace ecsnetpp
{

    class CPUCore : public cSimpleModule
    {
    protected:
        std::map<long, cQueue> processingQueueMap;
        //    cMessage *timerMsg = nullptr;
        cMessage *index;
        double perCoreFreq;
        double parallelisationFactor;
        long threadsPerCore;
        long totalCores;
        double delay;
        bool ackersEnabled;
        bool isOnEdgeDevice;

    protected:
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;
        virtual void finish() override;
        virtual omnetpp::SimTime calculateDelay(bool isProcessingDelayInCpuCycles, double processingDelay, long threads);
    };

} /* namespace ecsnetpp */

#endif /* CPU_CPUCORE_H_ */
