#ifndef __TLIST_H__
#define __TLIST_H__


template<class ValType>
class TList
{
private:
	struct TNode
	{
		ValType elem;
		TNode *pNext;
		TNode *pPrev;
	};
	TNode *pLast;
	TNode *pFirst;
	int count;
public:
	TList();
	~TList();
	void InSertFirst(const ValType &val);
	void InSertLast(const ValType &val);
	void InSertInPos(const int pos, const ValType &val);
	void DeleteFirst();
	void DeleteLast();
	void Delete(const int pos);
	void DeleteAll();
	ValType Show(const int pos);
	int GetSize(){return count;}
	bool operator==(const TList &list) const;
	bool operator!=(const TList &list) const;
	TList& operator=(const TList &list);

};
#endif 

template<class ValType>
 TList<ValType>::TList()
{
	pFirst = nullptr;
	pLast = nullptr;
	count = 0;
}

 template<class ValType>
 TList<ValType>::~TList()
 {
	 DeleteAll();
 }


template<class ValType>
void TList<ValType>::InSertFirst(const ValType &val)
{
	TNode *p = new TNode;
	p->elem = val;
	p->pPrev = nullptr;
	p->pNext = pFirst;

	if (pFirst != nullptr)
		pFirst->pPrev = p;
	if (count == 0)
		pFirst = pLast = p;
	else pFirst = p;

	count++;
}
template <class ValType>
void TList<ValType>::InSertInPos(const int pos,const ValType &val)
{
	if ((pos < 1) || (pos > count)) throw("incorrect position");
	if (pos == 1) InSertFirst(val);
	else if (pos == count) InSertLast(val);
	else
	{
		TNode *p = pFirst;
		for (int i = 1;i < pos;i++)
		{
			p = p->pNext;
		}
		TNode *tmp = new TNode;//новое звено
		TNode *prev = p->pPrev;//указывает на предыдущий
		
		tmp->elem = val;
		tmp->pNext = p;
		tmp->pPrev = prev;
		p->pPrev = tmp;

		count++;
	}
}
template<class ValType>
void TList<ValType>::InSertLast(const ValType  &val)
{
	TNode *p = new TNode;
	p->elem = val;
	p->pNext = nullptr;
	p->pPrev = pLast;

	if (pLast != nullptr)
		pLast->pNext= p;
	if (count == 0)
		pFirst = pLast = p;
	else pLast = p;

	count++;
}


template<class ValType>
 void TList<ValType>::DeleteFirst()
{
	 if (pFirst == nullptr) return;
	 TNode *p = pFirst->pNext;
	 delete pFirst;
	 pFirst = p;
	 count--;
	 if (pFirst == nullptr)
	 {
		 pLast = nullptr;
	 }
	 else pFirst->pPrev = nullptr;
}

 template<class ValType>
 inline void TList<ValType>::DeleteLast()
 {
	 if (pLast == nullptr) return;
	 TNode *p = pLast->pPrev;
	 delete pLast;
	 count--;
	 pLast = p;
	 if (pLast == nullptr)
		 pFirst = nullptr;
	 else pLast->pNext = nullptr;

 }

 template<class ValType>
 void TList<ValType>::Delete(const int pos)
 {
	 if (pos<1 || pos>count) return;
	 if (pos == 1) DeleteFirst();
	 else if (pos == count) DeleteLast();
	 else
	 {
		 TNode *p = pFirst;
		 for (int i = 1;i < pos;i++)
			 p = p->pNext;
		 TNode *prev = p->pPrev;
		 TNode *next = p->pNext;
		 delete p;;
		 prev->pNext = next;
		 next->pPrev = prev;
		 count--;
	 }
 }

 template<class ValType>
  void TList<ValType>::DeleteAll()
 {
	  if (count == 0) return;
	  while (count != 0)
		  DeleteFirst();
 }

template<class ValType>
 ValType TList<ValType>::Show(const int pos)
 {
	 if (pos<1 || pos>count) throw("there is no such position");
	 ValType tmp;
	 if (pos == 1) tmp = pFirst->elem;
	 else if (pos == count) tmp = pLast->elem;
	 else
	 {
		 TNode *p = pFirst;
		 for (int i = 1;i < pos;i++)
			 p = p->pNext;
		 tmp = p->elem;
	 }
	 return tmp;
 }

 template<class ValType>
 bool TList<ValType>::operator==(const TList<ValType> &list) const
 {
	 if (count != list.count)
		 return false;

	 TNode *tmp_one, *tmp_two;
	 tmp_one = pFirst;
	 tmp_two = list.pFirst;
	 while (tmp_one != nullptr)
	 {
		 if (tmp_one->elem != tmp_two->elem)
			 return false;
		 tmp_one = tmp_one->pNext;
		 tmp_two = tmp_two->pNext;
	 }
	 return true;
 }

 template<class ValType>
 bool TList<ValType>::operator!=(const TList & list) const
 {
	 if (*this == list) return false;
	 else return true;
 }

 template<class ValType>
 TList<ValType>& TList<ValType>::operator=(const TList<ValType> &list)
 {
	 if (*this == list) return *this;
	 DeleteAll();

	 TNode *tmp = list.pFirst;
	 while (tmp != nullptr)
	 {
		 InSertLast(tmp->elem);
			 tmp = tmp->pNext;
	 }
	 return *this;
 }
