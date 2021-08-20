#ifndef STASK_STREAMINGOPERATOR_H_
#define STASK_STREAMINGOPERATOR_H_

#include "omnetpp.h"
#include "../msg/StreamingMessage_m.h"
#include "ISTask.h"
#include "../model/operator/selectivity/IOperatorSelectivityDistribution.h"
#include "../model/operator/productivity/IOperatorProductivityDistribution.h"

using namespace omnetpp;

namespace ecsnetpp
{

    class StreamingOperator : public ISTask
    {
    private:
        int selectivityWindowLength;
        int selectivityWindowCount;

    protected:
        cQueue outgoingQueue;
        cQueue selectivityWindow;
        cMessage *timerMsg = nullptr;
        StreamingMessage *nextToSend;
        double selectivityRatio = 0;  // number of outgoing messages to be generated per each incoming message
        double productivityRatio = 0; // sizeof(outgoing msg)/sizeof(incoming msg)
        const char *myOperatorSelectivityDistributionModuleName;
        const char *myOperatorProductivityDistributionModuleName;
        bool isOperatorSelectivityDistributed = false;
        bool isOperatorProductivityDistributed = false;
        IOperatorSelectivityDistribution *myOperatorSelectivityDistributionModule;
        IOperatorProductivityDistribution *myOperatorProductivityDistributionModule;

    public:
        ////    StreamingTask();
        //    virtual ~StreamingOperator();
    protected:
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;
        virtual void finish() override;
        virtual double getSelectivityRatio();
        virtual double getSelectivityWindowLength();
        virtual double getProductivityRatio();
    };

} /* namespace ecsnetpp */

#endif /* STASK_STREAMINGOPERATOR_H_ */
