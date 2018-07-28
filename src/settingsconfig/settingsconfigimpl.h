#ifndef SETTINGSCONFIGIMPL_H
#define SETTINGSCONFIGIMPL_H

#include "settingsconfig.h"

class QFileSelector;

class SettingsConfigImpl : public SettingsConfigBase
{
protected:
	void setFilters(QString frontend, const QFileSelector *selector);
	void resetFilters();
	void setIncludesOptional(bool alwaysOptional);

	bool finish_group_content(QXmlStreamReader &reader, GroupContentGroup &data, bool hasNext) override;
	bool finish_section_content(QXmlStreamReader &reader, SectionContentGroup &data, bool hasNext) override;
	bool finish_category_content(QXmlStreamReader &reader, CategoryContentGroup &data, bool hasNext) override;
	bool finish_settings_config_content(QXmlStreamReader &reader, SettingsConfigContentGroup &data, bool hasNext) override;

private:
	template <typename TGroup>
	void finishContents(QXmlStreamReader &reader, TGroup &group);
	template <typename TIter, typename TList>
	bool readGeneralInclude(QXmlStreamReader &reader, IncludeType include, TIter &it, TList &list);

	bool isUsable(const SelectableContrainerInfo &element) const;

	QString _frontend;
	const QFileSelector *_selector = nullptr;
	bool _alwaysOptional = false;
};

#endif // SETTINGSCONFIGIMPL_H