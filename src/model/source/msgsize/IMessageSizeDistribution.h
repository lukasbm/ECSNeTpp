#ifndef __EDGECLOUDSTREAMINGSIMULATOR_IMESSAGESIZEDISTRIBUTION_H_
#define __EDGECLOUDSTREAMINGSIMULATOR_IMESSAGESIZEDISTRIBUTION_H_

#include <omnetpp.h>

using namespace omnetpp;

namespace ecsnetpp
{

  /**
 * TODO - Generated class
 */
  class IMessageSizeDistribution : public cSimpleModule
  {
  protected:
    virtual void initialize(){};

  public:
    virtual double getMsgSize();
  };

} //namespace

#endif
