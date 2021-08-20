#ifndef __EDGECLOUDSTREAMINGSIMULATOR_FIXEDSOURCEEVENTRATEDISTRIBUTION_H_
#define __EDGECLOUDSTREAMINGSIMULATOR_FIXEDSOURCEEVENTRATEDISTRIBUTION_H_

#include <omnetpp.h>

#include "ISourceEventRateDistribution.h"

using namespace omnetpp;

namespace ecsnetpp
{

  /**
 * TODO - Generated class
 */
  class FixedSourceEventRateDistribution : public ISourceEventRateDistribution
  {
  protected:
    double rate;
    double messageDelay;

  protected:
    virtual void initialize() override;

  public:
    virtual double getMessageDelay() override;
  };

} //namespace

#endif
