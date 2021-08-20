#include "IOperatorProductivityDistribution.h"

namespace ecsnetpp
{

    Define_Module(IOperatorProductivityDistribution);

    double IOperatorProductivityDistribution::getProductivityRatio()
    {
        throw new cRuntimeError("Operator productivity distribution function is not implemented.");
    }

} //namespace
