//#include "twoThreeTree.h"
//
//Point::Point(int num) {
//	Key[0] = num;
//	isTwo = true;
//	father = lSon = rSon = mSon = extra = nullptr;
//}
//Point::Point(int num, Point* _father, Point* _lSon, Point* _rSon) {
//	Key[0] = num;
//	isTwo = true;
//	father = _father;
//	lSon = _lSon;
//	rSon = _rSon;
//	mSon = extra = nullptr;
//}
//
//Point* Point::addKey(int num) {
//	if (isTwo) {
//		isTwo = false;
//		Key[1] = num;
//		if (Key[0] > Key[1])
//			swap(Key[0], Key[1]);
//		return nullptr;
//	}else{
//		if (Key[0] > num)
//			swap(Key[0], num);
//		if (num > Key[1])
//			swap(Key[1], num);
//		if (extra != nullptr) {
//			if (extra->Key[0] < mSon->Key[0])
//				swap(extra, mSon);
//			if (extra->Key[0] > (rSon->isTwo ? rSon->Key[0] : rSon->Key[1]))
//				swap(extra, rSon);
//		}
//		if (father == nullptr) {
//			Point * newone = new Point(Key[1], father, lSon, rSon);
//			Point * head = new Point(num, nullptr, this, newone);
//			newone->father = father = head;
//			isTwo = true;
//			return head;
//		}else {
//			if (father->isTwo) {
//				Point * newone;
//				if (extra == nullptr)
//					newone = new Point(Key[1], father, nullptr, nullptr);
//				else
//					newone = new Point(Key[1], father, extra, rSon);
//				extra = nullptr;
//				rSon = mSon;
//				mSon = nullptr;
//				father->mSon = newone;
//				isTwo = true;
//				father->addKey(num);
//			}else{
//				//alph版本不考虑了.
//				cout << "alph版本臣妾不支持，自杀谢罪" << endl;
//				system("pause");
//				exit(0);
//			}
//		}
//	}
//}
//
//bool Point::isLeaves() {
//	if (lSon == nullptr)
//		if (rSon == nullptr)
//			if (mSon == nullptr)
//				return false;
//	return true;
//}
//
//void Tree::addPoint(int num) {
//	Point *temp = findPlace(num);
//	if (temp == nullptr) {
//		temp = new Point(num);
//		head = temp;
//		display();
//		return;
//	}
//	temp = temp->addKey(num);
//	if (temp != nullptr)
//		head = temp;
//	display();
//}
//
//Point* Tree::findPlace(int num) {
//	if (head == nullptr)
//		return head;
//	Point *temp = head;
//	while (temp->isLeaves()) {
//		if (temp->isTwo) {
//			if (num < temp->Key[0])
//				temp = temp->lSon;
//			else
//				temp = temp->rSon;
//		}else {
//			if (num < temp->Key[0])
//				temp = temp->lSon;
//			else if (temp->Key[1] < num)
//				temp = temp->rSon;
//			else
//				temp = temp->mSon;
//		}
//		return temp;
//	}
//	return temp;
//}
//
//void Tree::display() {
//	deque<Point *> list;
//	if (head == nullptr)
//		return;
//	list.push_back(head);
//	for (Point*temp;;) {
//		temp = list[0];
//		list.pop_front();
//		if(temp ->isLeaves())
//			if (temp->isTwo) {
//				list.push_back(temp->lSon);
//				list.push_back(temp->rSon);
//			}else {
//				list.push_back(temp->lSon);
//				list.push_back(temp->mSon);
//				list.push_back(temp->rSon);
//			}
//		if (!temp->isTwo)
//			cout << temp->Key[0] << ',' << temp->Key[1] << '\t';
//		else
//			cout << temp->Key[0] << '\t';
//		if (list.empty()) {
//			cout << '\n' << endl;
//			return;
//		}
//	}
//}