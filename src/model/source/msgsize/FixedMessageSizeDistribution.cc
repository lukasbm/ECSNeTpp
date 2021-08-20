#include "FixedMessageSizeDistribution.h"

namespace ecsnetpp
{

    Define_Module(FixedMessageSizeDistribution);

    void FixedMessageSizeDistribution::initialize()
    {
        msgSize = par("msgsize").doubleValue();
    }

    double FixedMessageSizeDistribution::getMsgSize()
    {
        return msgSize;
    }

} //namespace
