#include "FixedProductivityDistribution.h"

namespace ecsnetpp
{

    Define_Module(FixedProductivityDistribution);

    void FixedProductivityDistribution::initialize()
    {
        productivityRatio = par("productivityratio").doubleValue();
    }

    double FixedProductivityDistribution::getProductivityRatio()
    {
        return productivityRatio;
    }

} //namespace
