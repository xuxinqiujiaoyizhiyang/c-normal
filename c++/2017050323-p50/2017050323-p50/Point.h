//��Point����������ʵ��
class Point {
public:
	//���캯�������и���Ա����������Ĭ��ֵ��ֵ��
	Point(int xx = 0, int yy = 0){
		X = xx;
		Y = yy;
		countP++;//����һ�ι�����Ծ�̬��Ա��������һ������
	}
	//�������캯��
	Point(Point &p) {
		X = p.X;
		Y = p.Y;
		countP++;//����һ�ο���������Ծ�̬��Ա��������һ������
	}
	//�����Ա����X��ֵ
	int GetX(){
		return X;
	}
	//�����Ա����Y��ֵ
	int GetY() {
		return Y;
	}
	//�����̬��Ա����countP��ֵ
	static int GetC() {
		return countP;
	}
	//������Ա����X,Y���Լ���̬��Ա����countP
private:
	int X, Y;
	static int countP;
};
//�Ծ�̬��Ա�������г�ʼ��
int Point::countP = 0;

