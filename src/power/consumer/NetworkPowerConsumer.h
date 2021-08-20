#ifndef POWER_CONSUMER_NETWORKPOWERCONSUMER_H_
#define POWER_CONSUMER_NETWORKPOWERCONSUMER_H_

#include "inet/physicallayer/contract/packetlevel/IRadio.h"
#include "inet/power/contract/IEpEnergyConsumer.h"
#include "inet/power/contract/IEpEnergySource.h"

using namespace inet;
using namespace inet::power;
using namespace inet::physicallayer;

namespace ecsnetpp
{

  class NetworkPowerConsumer : public cSimpleModule, public cListener
  {

  protected:
    double cpuPowerConsumptionScalar = NaN;
    // parameters
    W offPowerConsumption = W(NaN);
    W sleepPowerConsumption = W(NaN);
    W switchingPowerConsumption = W(NaN);
    W receiverIdlePowerConsumption = W(NaN);
    W receiverBusyPowerConsumption = W(NaN);
    W receiverReceivingPowerConsumption = W(NaN);
    W receiverReceivingPreamblePowerConsumption = W(NaN);
    W receiverReceivingHeaderPowerConsumption = W(NaN);
    W receiverReceivingDataPowerConsumption = W(NaN);
    W transmitterIdlePowerConsumption = W(NaN);
    W transmitterTransmittingPowerConsumption = W(NaN);
    W transmitterTransmittingPreamblePowerConsumption = W(NaN);
    W transmitterTransmittingHeaderPowerConsumption = W(NaN);
    W transmitterTransmittingDataPowerConsumption = W(NaN);

    // environment
    IRadio *radio = nullptr; // TODO handle multiple ethernet interfaces

    // state
    W powerConsumption = W(NaN);

  public:
    static simsignal_t networkPowerConsumptionChangedSignal;

  protected:
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual W computePowerConsumption() const;
    virtual void initialize(int stage) override;

  public:
    virtual W getPowerConsumption() const { return powerConsumption; }
    virtual void receiveSignal(cComponent *source, simsignal_t signal, long value, cObject *details) override;
  };

}
/* namespace ecsnetpp */

#endif /* POWER_CONSUMER_STREAMINGENERGYCONSUMER_H_ */
