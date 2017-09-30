#pragma once
class ActorFactory
{

	ActorId m_lastActorId;

protected:
	GenericObjectFactory<ActorComponent, ComponentId>
		m_componentFactory;
public:
	ActorFactory(void);
	StrongActorPtr CreateActor(const char* actorResource);
protected:
	virtual StrongActorComponentPtr CreateComponent(TiXmlElement*
		pData);
private:
	ActorId GetNextActorId(void)
	{
		++m_lastActorId; return
			m_lastActorId;
	}
};