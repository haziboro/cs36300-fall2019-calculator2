// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size, see header file for more info
//
template <typename T>
inline
size_t Queue<T>::size(void) const
{
	return size_;
}

//
// is_empty, see header file for more info
//
template <typename T>
inline
bool Queue<T>::is_empty(void) const
{
	if (size_ == 0) {
		return true;
	}
	else {
		return false;
	}
}