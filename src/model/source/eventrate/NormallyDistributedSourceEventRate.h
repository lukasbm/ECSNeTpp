#ifndef MODEL_SOURCE_EVENTRATE_NORMALLYDISTRIBUTEDSOURCEEVENTRATE_H_
#define MODEL_SOURCE_EVENTRATE_NORMALLYDISTRIBUTEDSOURCEEVENTRATE_H_

#include "omnetpp.h"

#include "ISourceEventRateDistribution.h"

using namespace omnetpp;

namespace ecsnetpp
{

    class NormallyDistributedSourceEventRate : public ISourceEventRateDistribution
    {
    protected:
        double mean;
        double stddev;

    protected:
        virtual void initialize() override;

    public:
        virtual double getMessageDelay() override;
    };

} /* namespace ecsnetpp */

#endif /* MODEL_SOURCE_EVENTRATE_NORMALLYDISTRIBUTEDSOURCEEVENTRATE_H_ */
