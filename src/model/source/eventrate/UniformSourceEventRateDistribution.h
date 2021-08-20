#ifndef __EDGECLOUDSTREAMINGSIMULATOR_UNIFORMSOURCEEVENTRATEDISTRIBUTION_H_
#define __EDGECLOUDSTREAMINGSIMULATOR_UNIFORMSOURCEEVENTRATEDISTRIBUTION_H_

#include <omnetpp.h>

#include "ISourceEventRateDistribution.h"

using namespace omnetpp;

namespace ecsnetpp
{

  /**
 * TODO - Generated class
 */
  class UniformSourceEventRateDistribution : public ISourceEventRateDistribution
  {
  protected:
    double begin;
    double end;

  protected:
    virtual void initialize() override;

  public:
    virtual double getMessageDelay() override;
  };

} //namespace

#endif
