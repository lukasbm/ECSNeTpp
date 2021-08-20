#include "FixedSourceEventRateDistribution.h"

namespace ecsnetpp
{

    Define_Module(FixedSourceEventRateDistribution);

    void FixedSourceEventRateDistribution::initialize()
    {
        rate = getAncestorPar("fixedSourceEventRate").doubleValue();
        if (rate > 0)
        {
            messageDelay = 1 / rate;
        }
        else
        {
            throw cRuntimeError("Event rate is not set for the source : %s", getFullPath().c_str());
        }
    }

    double FixedSourceEventRateDistribution::getMessageDelay()
    {
        return messageDelay;
    }

} //namespace
