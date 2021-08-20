#ifndef __EDGECLOUDSTREAMINGSIMULATOR_IOPERATORPRODUCTIVITYDISTRIBUTION_H_
#define __EDGECLOUDSTREAMINGSIMULATOR_IOPERATORPRODUCTIVITYDISTRIBUTION_H_

#include <omnetpp.h>

using namespace omnetpp;

namespace ecsnetpp
{

  /**
 * TODO - Generated class
 */
  class IOperatorProductivityDistribution : public cSimpleModule
  {
  protected:
    virtual void initialize(){};

  public:
    virtual double getProductivityRatio();
  };

} //namespace

#endif
