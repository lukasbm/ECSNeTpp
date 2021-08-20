#ifndef MODEL_SOURCE_EVENTRATE_ISOURCEEVENTRATEDISTRIBUTION_H_
#define MODEL_SOURCE_EVENTRATE_ISOURCEEVENTRATEDISTRIBUTION_H_
#include "omnetpp.h"

using namespace omnetpp;

namespace ecsnetpp
{

    class ISourceEventRateDistribution : public cSimpleModule
    {
    protected:
        virtual void initialize(){};

    public:
        virtual double getMessageDelay();
    };

} /* namespace ecsnetpp */

#endif /* MODEL_SOURCE_EVENTRATE_ISOURCEEVENTRATEDISTRIBUTION_H_ */
