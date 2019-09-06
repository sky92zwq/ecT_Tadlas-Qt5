#pragma once
class mode
{
public:
	mode();
	~mode();
	enum ET {
		ECT,
		TDlas
	};
	static  ET m_mode;
};

