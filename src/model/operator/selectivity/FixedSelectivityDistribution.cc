#include "FixedSelectivityDistribution.h"

namespace ecsnetpp
{

    Define_Module(FixedSelectivityDistribution);

    void FixedSelectivityDistribution::initialize()
    {
        selectivityRatio = par("selectivityratio").doubleValue();
        selectivityWindowLength = std::lround(1 / selectivityRatio);
    }

    double FixedSelectivityDistribution::getSelectivityRatio()
    {
        return selectivityRatio;
    }

    double FixedSelectivityDistribution::getSelectivityWindowLength()
    {
        return selectivityWindowLength;
    }

} //namespace
