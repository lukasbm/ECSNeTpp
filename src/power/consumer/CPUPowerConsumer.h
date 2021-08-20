#ifndef POWER_CONSUMER_CPUPOWERCONSUMER_H_
#define POWER_CONSUMER_CPUPOWERCONSUMER_H_

#include "inet/power/contract/IEpEnergySource.h"
#include "inet/power/contract/IEpEnergyConsumer.h"
#include "inet/common/ModuleAccess.h"
#include "../../stask/ISTask.h"

using namespace inet;
using namespace inet::power;

namespace ecsnetpp
{

    class CPUPowerConsumer : public cSimpleModule, public cListener
    {
    protected:
        double cpuPowerConsumptionScalar = NaN;
        double cpuBusyUtilisation;
        double cpuIdleUtilisation;
        W idlePowerConsumption = W(NaN);
        IEpEnergySource *energySource = nullptr;

        // state
        mutable States::CPUState prevState;
        W powerConsumption = W(NaN);

    public:
        static simsignal_t cpuPowerConsumptionChangedSignal;

    protected:
        virtual int numInitStages() const override { return NUM_INIT_STAGES; }
        virtual void initialize(int stage) override;
        virtual W computeCPUPowerConsumption(double value) const;

    public:
        virtual IEnergySource *getEnergySource() const { return energySource; }
        virtual W getPowerConsumption() const { return powerConsumption; }

        virtual void receiveSignal(cComponent *source, simsignal_t signal, long value, cObject *details) override;
    };

} /* namespace ecsnetpp */

#endif /* POWER_CONSUMER_CPUEPENERGYCONSUMER_H_ */
