#include "IOperatorSelectivityDistribution.h"

namespace ecsnetpp
{

    Define_Module(IOperatorSelectivityDistribution);

    double IOperatorSelectivityDistribution::getSelectivityRatio()
    {
        throw new cRuntimeError("Operator selectivity distribution function is not implemented.");
    }

    double IOperatorSelectivityDistribution::getSelectivityWindowLength()
    {
        throw new cRuntimeError("Operator selectivity distribution window length function is not implemented.");
    }
} //namespace
