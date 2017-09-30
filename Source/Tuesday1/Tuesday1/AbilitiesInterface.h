#pragma once

class AbilitiesInterface 
{
public:

	typedef std::map<ComponentId, StrongActorComponentPtr> ActorComponents;
	const static ComponentId COMPONENT_ID;
	virtual ComponentId VGetComponentId(void) const
	{
		return COMPONENT_ID;
	}
	
	bool Init(TiXmlElement* pData);
	void PostInit(void);
	void Destroy(void);
	void Update(int deltaMs);

};