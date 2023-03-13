#pragma once

class Indices
{
public:
	Indices(int index) : _index(index) {}
	int Get() const { return _index; }
	void Set(int index) { _index = index; }

private:
	int _index;
};