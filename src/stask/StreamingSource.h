#ifndef STASK_STREAMINGSOURCE_H_
#define STASK_STREAMINGSOURCE_H_

#include "omnetpp.h"
#include "../msg/StreamingMessage_m.h"
#include "ISTask.h"
#include "../common/SimulationController.h"
#include "../model/source/eventrate/ISourceEventRateDistribution.h"
#include "../model/source/msgsize/IMessageSizeDistribution.h"

using namespace omnetpp;

namespace ecsnetpp
{

    class StreamingSource : public ISTask
    {
    protected:
        cQueue outgoingQueue;
        cMessage *timerMsg = nullptr;
        double msgSize = 0;
        double eventRate = 0;
        double msgDelay = 0;
        bool isSourceEvRateDistributed = false;
        bool isSourceMsgSizeDistributed = false;
        const char *mySourceEvRateDistributionModuleName;
        const char *mySourceMsgSizeDistributionModuleName;
        SimulationController *commonSimController;
        ISourceEventRateDistribution *mySourceEvRateDistributionModule;
        IMessageSizeDistribution *mySourceMsgSizeDistributionModule;

    public:
        virtual ~StreamingSource();

    protected:
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;
        virtual double getMessageDelay();
        virtual double getMessageSize();
    };

} /* namespace ecsnetpp */

#endif /* STASK_STREAMINGSOURCE_H_ */
