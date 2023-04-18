#pragma

class InvalidInitList {
private:
	const char* message = "[ERROR] Invalid init list usage!\nMatrix must be nxn size!";
public:
	InvalidInitList() = default;

	const char* info() const {
		return message;
	}
};