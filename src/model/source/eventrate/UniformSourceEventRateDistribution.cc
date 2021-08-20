#include "UniformSourceEventRateDistribution.h"

namespace ecsnetpp
{

    Define_Module(UniformSourceEventRateDistribution);

    void UniformSourceEventRateDistribution::initialize()
    {
        begin = par("begin").doubleValue();
        end = par("end").doubleValue();
    }

    double UniformSourceEventRateDistribution::getMessageDelay()
    {
        return uniform(begin, end);
    }

} //namespace
