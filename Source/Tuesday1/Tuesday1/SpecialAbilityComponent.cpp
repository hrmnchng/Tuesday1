
#include "SpecialAbilityComponent.h"

bool SpecialAbilityComponent::VInit(TiXmlElement* pData)
{
	return true;

}
void SpecialAbilityComponent::VApply(WeakActorPtr pActor)
{
	cout <<"special" << (string)(pStrongActor->GetId());
}
