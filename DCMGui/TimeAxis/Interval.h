#ifndef INTERVAL_H
#define INTERVAL_H

#include "DSGuiGlobal.h"
#include <QList>

class Interval;
typedef QList<Interval>  IntervalList;
class Interval
{
public:
	qint64 start,end;
	Interval(qint64 s,qint64 e):start(s),end(e){}
	Interval():start(0),end(0){}
	inline bool valid() const;
	inline void reset();
	inline qint64 interval()const;
	//-1,С�ڸ����䣻1,���ڸ����䣻=0,����
	inline int contain(qint64 time) const;
	inline bool operator<(const Interval&that) const;
	inline bool operator==(const Interval&that) const;
	inline Interval intersect(const Interval&)const;
	inline IntervalList unintersect(const Interval&)const;
	//�����н��������伯�ϣ�mergedInvs����Ϊ�ϲ��������伯��
	IntervalList intersect(const IntervalList& mergedInvs) const;
	//������mergerdInvs�н�����Ƭ�Σ�mergedInvs����Ϊ�ϲ��������伯�ϣ����ؽ��Ϊthis���Ӽ�
	IntervalList unintersect(const IntervalList& mergedInvs) const;

	//����ϲ�,���غϲ�����������伯��
	static IntervalList merge(IntervalList& invs);
	//������reg�н��������伯��,mergedInvs����Ϊ�������伯��
	static IntervalList intersect(const Interval& reg, const IntervalList& mergedInvs);
	//��������srcInvs��cmpList�Ľ��������붼�Ǻϲ��������伯�ϣ�����srcInvs���Ӽ���
	static IntervalList unintersect(const IntervalList& srcInvs, const IntervalList& cmpList);
};

inline bool Interval::valid() const
{
	return start>=0 && end>start;
}

inline void Interval::reset()
{
	end = start = 0;
}

inline qint64 Interval::interval() const
{
	return (end-start);
}

inline bool Interval::operator<(const Interval&that) const
{
	return this->start < that.start;
}

inline bool Interval::operator==(const Interval&that) const
{
	return this->start == that.start && this->end == that.end;
}

inline int Interval::contain(qint64 time) const
{
	if(time>end)
		return 1;
	if(time<start)
		return -1;
	return 0;
}

inline Interval Interval::intersect( const Interval& that) const
{
	if(start>=that.end || end<=that.start)
	{
		return Interval();
	}
	return Interval(qMax(start,that.start),qMin(end,that.end));
}

inline IntervalList Interval::unintersect( const Interval& that) const
{
	IntervalList listRet;
	if(start>=that.end || end<=that.start)
	{
		listRet.push_back(*this);
		return listRet;
	}	
	if(end<=that.end && start>=that.start)
	{
		return listRet;  //��
	}
	if(end>that.end && start < that.start)
	{
		listRet.push_back(Interval(start,that.start));
		listRet.push_back(Interval(that.end,end));
		return listRet;
	}
	if(start<that.start)
	{
		listRet.push_back(Interval(start,that.start));
		return listRet;
	}
	if(end>that.end)
	{
		listRet.push_back(Interval(that.end,end));
		return listRet;
	}
	return listRet;
}

DS_GUI_EXPORT QDebug operator<<( QDebug dbg, const Interval &vector );
DS_GUI_EXPORT QDebug operator<<( QDebug dbg, const IntervalList &vector );

#endif // 
