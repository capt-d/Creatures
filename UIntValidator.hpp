/* 
 * Based on 
 * https://forum.qt.io/topic/115662/qintvalidator-for-unsigned-long-values
 * by 
 * https://forum.qt.io/user/vronin
 */
#ifndef UIV_H
#define UIV_H

#include <QValidator>


class UIntValidator : public QValidator {
    Q_OBJECT
public:
    UIntValidator(unsigned int minimum, unsigned int maximum, QObject *parent = nullptr):QValidator(parent), m_min(minimum), m_max(maximum){}

    UIntValidator(QObject *parent = nullptr):UIntValidator(std::numeric_limits<unsigned int>::min(), std::numeric_limits<unsigned int>::max(), parent)
    {}
    unsigned int bottom() const { return m_min; }
    unsigned int top() const { return m_max; }
    void setBottom(unsigned int minimum){
        if(m_min==minimum)
            return;
        m_min=minimum;
        changed();
    }
    void setTop(unsigned int maximum){
        if(m_max==maximum)
            return;
        m_max=maximum;
        changed();
    }
    void setRange(unsigned int minimum, unsigned int maximum){
        setBottom(minimum);
        setTop(maximum);
    }
    QValidator::State validate(QString &input, int&) const override{
        bool convertOk=false;
        unsigned int numInput = input.toUInt(&convertOk);
        if(!convertOk)
            return QValidator::Invalid;
        if(numInput<m_min)
            return QValidator::Intermediate;
        if(numInput>m_max)
            return QValidator::Invalid;
        return QValidator::Acceptable;
    }
    ~UIntValidator(){};
    void fixup(QString &input) const{};

private:
    unsigned int m_min;
    unsigned int m_max;
    
};

#endif 
