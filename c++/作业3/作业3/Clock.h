class Clock{
public:
	Clock(int NewH, int NewM, int NewS);
	~Clock();
	void SetTime(int NewH, int NewM, int NewS);
	void ShowTime();

private:
	int Hour, Minute, Second;
};
