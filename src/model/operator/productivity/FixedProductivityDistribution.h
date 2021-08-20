#ifndef __EDGECLOUDSTREAMINGSIMULATOR_FIXEDPRODUCTIVITYDISTRIBUTION_H_
#define __EDGECLOUDSTREAMINGSIMULATOR_FIXEDPRODUCTIVITYDISTRIBUTION_H_

#include <omnetpp.h>
#include "IOperatorProductivityDistribution.h"

using namespace omnetpp;

namespace ecsnetpp
{

  /**
 * TODO - Generated class
 */
  class FixedProductivityDistribution : public IOperatorProductivityDistribution
  {
  protected:
    double productivityRatio;

  protected:
    virtual void initialize() override;

  public:
    virtual double getProductivityRatio() override;
  };

} //namespace

#endif
