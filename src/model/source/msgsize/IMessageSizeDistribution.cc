#include "IMessageSizeDistribution.h"

namespace ecsnetpp
{

    Define_Module(IMessageSizeDistribution);

    double IMessageSizeDistribution::getMsgSize()
    {
        throw new cRuntimeError("Source message size distribution function is not implemented.");
    }

} //namespace
