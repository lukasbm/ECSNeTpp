#ifndef __EDGECLOUDSTREAMINGSIMULATOR_IOPERATORSELECTIVITYDISTRIBUTION_H_
#define __EDGECLOUDSTREAMINGSIMULATOR_IOPERATORSELECTIVITYDISTRIBUTION_H_

#include <omnetpp.h>

using namespace omnetpp;

namespace ecsnetpp
{

  /**
 * TODO - Generated class
 */
  class IOperatorSelectivityDistribution : public cSimpleModule
  {
  protected:
    virtual void initialize(){};

  public:
    virtual double getSelectivityRatio();
    virtual double getSelectivityWindowLength();
  };

} //namespace

#endif
