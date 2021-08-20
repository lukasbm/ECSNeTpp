#include "NormallyDistributedSourceEventRate.h"

namespace ecsnetpp
{

    Define_Module(NormallyDistributedSourceEventRate);

    void NormallyDistributedSourceEventRate::initialize()
    {
        mean = par("mean").doubleValue();
        stddev = par("stddev").doubleValue();
    }

    double NormallyDistributedSourceEventRate::getMessageDelay()
    {
        double val = truncnormal(mean, stddev);
        std::cout << val << endl;
        return val;
    }

} /* namespace ecsnetpp */
