#ifndef PART_H
#define PART_H

#include <QDomElement>

class Part
{
private:
    QString contentDisposition;     // cd
    QString charSet;                // chset
    QString contentId;              // cid
    QString contentLocation;        // cl
    QString contentType;            // ct
    QString contentTypeStart;       // ctt_s
    QString contentTypeType;        // ctt_t
    QString data;
    QString filename;               // fn
    QString name;
    QString sequence;               // seq
    QString text;
public:
    Part() { }
    Part(const QDomElement& element);
    Part(const Part& copy) : contentDisposition(copy.contentDisposition),
        charSet(copy.charSet),
        contentId(copy.contentId),
        contentLocation(copy.contentLocation),
        contentType(copy.contentType),
        contentTypeStart(copy.contentTypeStart),
        contentTypeType(copy.contentTypeType),
        data(copy.data),
        filename(copy.filename),
        name(copy.name),
        sequence(copy.sequence),
        text(copy.text) { }
    Part(const QString& contentDisposition,
         const QString& charSet,
         const QString& contentId,
         const QString& contentLocation,
         const QString& contentType,
         const QString& contentTypeStart,
         const QString& contentTypeType,
         const QString& data,
         const QString& filename,
         const QString& name,
         const QString& sequence,
         const QString& text) : contentDisposition(contentDisposition),
        charSet(charSet),
        contentId(contentId),
        contentLocation(contentLocation),
        contentType(contentType),
        contentTypeStart(contentTypeStart),
        contentTypeType(contentTypeType),
        data(data),
        filename(filename),
        name(name),
        sequence(sequence),
        text(text) { }
    void operator= (const Part& copy) {
        this->contentDisposition = copy.contentDisposition;
        this->charSet = copy.charSet;
        this->contentId = copy.contentId;
        this->contentLocation = copy.contentLocation;
        this->contentType = copy.contentType;
        this->contentTypeStart = copy.contentTypeStart;
        this->contentTypeType = copy.contentTypeType;
        this->data = copy.data;
        this->filename = copy.filename;
        this->name = copy.name;
        this->sequence = copy.sequence;
        this->text = copy.text;
    }

    const QString getContentDisposition() const { return this->contentDisposition; }
    const QString getCharSet() const { return this->charSet; }
    const QString getContentId() const { return this->contentId; }
    const QString getContentLocation() const { return this->contentLocation; }
    const QString getContentType() const { return this->contentType; }
    const QString getContentTypeStart() const { return this->contentTypeStart; }
    const QString getContentTypeType() const { return this->contentTypeType; }
    const QString getData() const { return this->data; }
    const QString getFilename() const { return this->filename; }
    const QString getName() const { return this->name; }
    const QString getSequence() const { return this->sequence; }
    const QString getText() const { return this->text; }
};

#endif // PART_H
