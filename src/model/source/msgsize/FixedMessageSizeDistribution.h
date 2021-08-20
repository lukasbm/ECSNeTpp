#ifndef __EDGECLOUDSTREAMINGSIMULATOR_FIXEDMESSAGESIZEDISTRIBUTION_H_
#define __EDGECLOUDSTREAMINGSIMULATOR_FIXEDMESSAGESIZEDISTRIBUTION_H_

#include <omnetpp.h>
#include "IMessageSizeDistribution.h"

using namespace omnetpp;

namespace ecsnetpp
{

  /**
 * TODO - Generated class
 */
  class FixedMessageSizeDistribution : public IMessageSizeDistribution
  {
  protected:
    double msgSize;

  protected:
    virtual void initialize() override;

  public:
    virtual double getMsgSize() override;
  };

} //namespace

#endif
