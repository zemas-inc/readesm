#ifndef HTMLREPORTER_H
#define HTMLREPORTER_H

#include "Reporter.h"

class HtmlReporter : public Reporter {
	Q_DECLARE_TR_FUNCTIONS(HtmlReporter)
protected:
	int linkNumber;
	int toggleNumber;
	QByteArray linkCollected;
	mutable QTextStream linkCollector;
	QString toggleAbleBlocks(const QString& title, bool showByDefault);
	virtual void subBlock(const Block& value, const QString& tag);
	virtual void arrayStart(int count, const QString& title, bool defaultShown);
	virtual void arrayEnd(int count);
public:
	HtmlReporter();
	virtual void tagValuePair(const QString& tag, const QString& value);
	QByteArray toQByteArray() const;
	virtual bool allowSvg() const;
};


#endif
