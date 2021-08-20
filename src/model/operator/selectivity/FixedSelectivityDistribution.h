#ifndef __EDGECLOUDSTREAMINGSIMULATOR_FIXEDSELECTIVITYDISTRIBUTION_H_
#define __EDGECLOUDSTREAMINGSIMULATOR_FIXEDSELECTIVITYDISTRIBUTION_H_

#include <omnetpp.h>
#include "IOperatorSelectivityDistribution.h"

using namespace omnetpp;

namespace ecsnetpp
{

  /**
 * TODO - Generated class
 */
  class FixedSelectivityDistribution : public IOperatorSelectivityDistribution
  {
  protected:
    double selectivityRatio = 0;
    long selectivityWindowLength;

  protected:
    virtual void initialize() override;

  public:
    virtual double getSelectivityRatio() override;
    virtual double getSelectivityWindowLength() override;
  };

} //namespace

#endif
