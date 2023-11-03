#include "s21_string.h"

#ifdef __APPLE__
static const char* mac_error_messages[] = {
	"Operation not permitted",
	"No such file or directory",
	"No such process",
	"Interrupted system call",
	"Input/output error",
	"Device not configured",
	"Argument list too long",
	"Exec format error",
	"Bad file descriptor",
	"No child processes",
	"Resource deadlock avoided",
	/* 11 was EAGAIN */
	"Cannot allocate memory",
	"Permission denied",
	"Bad address",
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
	"Block device required",
#endif
	"Device / Resource busy",
	"File exists",
	"Cross-device link",
	"Operation not supported by device",
	"Not a directory",
	"Is a directory",
	"Invalid argument",
	"Too many open files in system",
	"Too many open files",
	"Inappropriate ioctl for device",
	"Text file busy",
	"File too large",
	"No space left on device",
	"Illegal seek",
	"Read-only file system",
	"Too many links",
	"Broken pipe",
	"Numerical argument out of domain",
	"Result too large",
	"Resource temporarily unavailable",
	"Operation would block",
	"Operation now in progress",
	"Operation already in progress",
	"Socket operation on non-socket",
	"Destination address required",
	"Message too long",
	"Protocol wrong type for socket",
	"Protocol not available",
	"Protocol not supported",
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
	"Socket type not supported",
#endif
	"Operation not supported",
#if !__DARWIN_UNIX03 && !defined(KERNEL)
	"Operation not supported on socket",
#endif
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
	"Protocol family not supported",
#endif
	"Address family not supported by protocol family",
	"Address already in use",
	"Can't assign requested address",
	"Network is down",
	"Network is unreachable",
	"Network dropped connection on reset",
	"Software caused connection abort",
	"Connection reset by peer",
	"No buffer space available",
	"Socket is already connected",
	"Socket is not connected",
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
	"Can't send after socket shutdown",
	"Too many references: can't splice",
#endif
	"Operation timed out",
	"Connection refused",
	"Too many levels of symbolic links",
	"File name too long",
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
	"Host is down",
#endif
	"No route to host",
	"Directory not empty",
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
	"Too many processes",
	"Too many users",
#endif
	"Disc quota exceeded",
	"Stale NFS file handle",
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
	"Too many levels of remote in path",
	"RPC struct is bad",
	"RPC version wrong",
	"RPC prog. not avail",
	"Program version wrong",
	"Bad procedure for program",
#endif
	"No locks available",
	"Function not implemented",
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
	"Inappropriate file type or format",
	"Authentication error",
	"Need authenticator",
	"Device power is off",
	"Device error, e.g. paper out",
#endif
	"Value too large to be stored in data type",
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
	"Bad executable",
	"Bad CPU type in executable",
	"Shared library version mismatch",
	"Malformed Macho file",
#endif
	"Operation canceled",
	"Identifier removed",
	"No message of desired type",
	"Illegal byte sequence",
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
	"Attribute not found",
#endif
	"Bad message",
	"Reserved",
	"No message available on STREAM",
	"Reserved",
	"No STREAM resources",
	"Not a STREAM",
	"Protocol error",
	"STREAM ioctl timeout",
#if __DARWIN_UNIX03 || defined(KERNEL)
	"Operation not supported on socket",
#endif
	"No such policy registered",
#if __DARWIN_C_LEVEL >= 200809L
	"State not recoverable",
	"Previous owner died",
#endif
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
	"Interface output queue is full",
	"Must be equal largest errno"
#endif
};

#elif defined(__linux__)
static const char* linux_error_messages[] = {
	"Operation not permitted",
	"No such file or directory",
	"No such process",
	"Interrupted system call",
	"Input/output error",
	"No such device or address",
	"Argument list too long",
	"Exec format error",
	"Bad file descriptor",
	"No child processes",
	"Resource deadlock avoided",
	"Cannot allocate memory",
	"Permission denied",
	"Bad address",
	"Block device required",
	"Device / Resource busy",
	"File exists",
	"Cross-device link",
	"Operation not supported by device",
	"Not a directory",
	"Is a directory",
	"Invalid argument",
	"Too many open files in system",
	"Too many open files",
	"Inappropriate ioctl for device",
	"Text file busy",
	"File too large",
	"No space left on device",
	"Illegal seek",
	"Read-only file system",
	"Too many links",
	"Broken pipe",
	"Math argument out of domain of func",
	"Math result not representable",
	"Resource deadlock would occur",
	"File name too long",
	"No record locks available",
	"Function not implemented",
	"Directory not empty",
	"Too many symbolic links encountered",
	"Operation would block",
	"No message of desired type",
	"Identifier removed",
	"Channel number out of range",
	"Level 2 not synchronized",
	"Level 3 halted",
	"Level 3 reset",
	"Link number out of range",
	"Protocol driver not attached",
	"No CSI structure available",
	"Level 2 halted",
	"Invalid exchange",
	"Invalid request descriptor",
	"Exchange full",
	"No anode",
	"Invalid request code",
	"Invalid slot",
	"Resource deadlock avoided",
	"Bad font file format",
	"Device not a stream",
	"No data available",
	"Timer expired",
	"Out of streams resources",
	"Machine is not on the network",
	"Package not installed",
	"The object is remote",
	"Advertise error",
	"Srmount error",
	"Communication error on send",
	"Protocol error",
	"Multihop attempted",
	"RFS specific error",
	"Bad message",
	"Value too large for defined data type",
	"Name not unique on network",
	"File descriptor in bad state",
	"Remote address changed",
	"Can not access a needed shared library",
	"Accessing a corrupted shared library",
	".lib section in a.out corrupted",
	"Attempting to link in too many shared libraries",
	"Cannot exec a shared library directly",
	"Invalid or incomplete multibyte or wide character",
	"Interrupted system call should be restarted",
	"Streams pipe error",
	"Too many users",
	"Socket operation on non-socket",
	"Destination address required",
	"Message too long",
	"Protocol wrong type for socket",
	"Protocol not available",
	"Protocol not supported",
	"Socket type not supported",
	"Operation not supported",
	"Protocol family not supported",
	"Address family not supported by protocol",
	"Address already in use",
	"Can't assign requested address",
	"Network is down",
	"Network is unreachable",
	"Network dropped connection on reset",
	"Software caused connection abort",
	"Connection reset by peer",
	"No buffer space available",
	"Socket is already connected",
	"Socket is not connected",
	"Can't send after socket shutdown",
	"Too many references: can't splice",
	"Operation timed out",
	"Connection refused",
	"Host is down",
	"No route to host",
	"Directory not empty",
	"Too many processes",
	"Too many users",
	"Disc quota exceeded",
	"Stale NFS file handle",
	"Too many levels of remote in path",
	"RPC struct is bad",
	"RPC version wrong",
	"RPC prog. not avail",
	"Program version wrong",
	"Bad procedure for program",
	"No locks available",
	"Function not implemented",
	"Inappropriate file type or format",
	"Authentication error",
	"Need authenticator",
	"Device power is off",
	"Device error, e.g. paper out",
	"Value too large to be stored in data type",
	"Bad executable",
	"Bad CPU type in executable",
	"Shared library version mismatch",
	"Malformed Macho file",
	"Operation canceled",
	"Identifier removed",
	"No message of desired type",
	"Illegal byte sequence",
	"Attribute not found",
	"Bad message",
	"No message available on STREAM",
	"No STREAM resources",
	"Not a STREAM",
	"Protocol error",
	"STREAM ioctl timeout",
	"Operation not supported on socket",
	"No such policy registered",
	"State not recoverable",
	"Previous owner died",
	"Interface output queue is full",
	"Must be equal largest errno"
};

#endif

s21_size_t s21_strlen(const char* str) {
	s21_size_t length = 0;
	while (str[length] != '\0') {
		length++;
	}
	return length;
}


const void* s21_memchr(const void* str, int c, s21_size_t n) {
	uint8_t* char_str = (uint8_t*)str;
	uint8_t uc = (uint8_t)c;
	for (s21_size_t i = 0; i < n; i++) {
		if (char_str[i] == uc) {
			return (void*)(char_str + i);
		}
	}
	return S21_NULL;
}


int s21_memcmp(const void* str1, const void* str2, s21_size_t n) {
	uint8_t* __s1 = (uint8_t*)str1;
	uint8_t* __s2 = (uint8_t*)str2;
	for (s21_size_t i = 0; i < n; i++) {
		if (__s1[i] < __s2[i]) {
			return -1;
		} else if (__s1[i] > __s2[i]){
			return 1;
		}
	}
	return 0;
}


void* s21_memcpy(void* dest, const void* src, s21_size_t n) {
	uint8_t* __d = (uint8_t*)dest;
	uint8_t* __s = (uint8_t*)src;
	for (size_t i = 0; i < n; i++) {
		__d[i] = __s[i];
	}
	return __d;
}


void* s21_memset(void* str, int c, s21_size_t n) {
	uint8_t* __s = (uint8_t*)str;
	uint8_t __c = (uint8_t)c;
	for (s21_size_t i = 0; i < n; i++) {
		__s[i] = c;
	}
	return (void*)__s;
}


char* s21_strncat(char* dest, const char* src, s21_size_t n) {
	s21_size_t __ld = s21_strlen(dest);
	s21_size_t __la = __ld + n;
	char* __a = (char*)malloc(__la + 1);
	if (__a == S21_NULL) {
		return S21_NULL;
	}
	for (s21_size_t i = 0; i < __ld; i++) {
		__a[i] = dest[i];
	}
	for (s21_size_t i = 0; i < n; i++) {
		__a[__ld + i] = src[i];
	}
	__a[__la] = '\0';
	return __a;
}


char* s21_strchr(const char* str, int c) {
	s21_size_t __ls = s21_strlen(str);
	s21_size_t __lr = 0;
	for (s21_size_t i = 0; i < __ls; i++) {
		if (str[i] == c) {
			__lr = i;
			break;
		}
	}
	if (__lr == 0) {
		return S21_NULL;
	}
	char* __a = (char*)malloc(__ls -__lr + 1);
	if (__a == S21_NULL) {
		return S21_NULL;
	}
	for (s21_size_t i = 0; i < __ls - __lr; i++) {
		__a[i] = str[__lr + i];
	}
	__a[__ls - __lr] = '\0';
	return __a;
}


int s21_strncmp(const char* str1, const char* str2, s21_size_t n) {
	s21_size_t __l = n;
	while (n--) {
		if (*str1 != *str2) {
			return (int)(unsigned char)(*str1) - (int)(unsigned char)(*str2);
		}
		if (*str1 == '\0') {
			break;
		}
	}
	return 0;
}


char* s21_strncpy(char* dest, const char* src, s21_size_t n) {
	for (s21_size_t i = 0; i < n; i++) {
		dest[i] = src[i];
	}
	return dest;
}


s21_size_t s21_strcspn(const char* str1, const char* str2) {
	uint8_t* __s1 = (uint8_t*)str1;
	uint8_t* __s2;
	s21_size_t length = 0;
	while (*__s1) {
		__s2 = (uint8_t*)str2;
		while (*__s2) {
			if (*__s1 == *__s2) {
				return length;
			}
			__s2++;
		}
		__s1++;
		length++;
	}
	return length;
}


char* s21_strerror(int errnum) {
	 char** error_messages = S21_NULL;

	#ifdef __APPLE__
	error_messages = mac_error_messages;
	#elif defined(__linux__)
	error_messages = linux_error_messages;
	#endif
	if (errnum >= 0 && errnum < sizeof(error_messages) / sizeof(error_messages[0])) {
		return (char*)error_messages[errnum];
	}
	return (char*)"Unknown error";
}

 
char* s21_strpbrk(const char* str1, const char* str2) {
	for (const char* __s1 = str1; *__s1 != '\0'; __s1++) {
		for (const char* __s2 = str2; *__s2 != '\0'; __s2++) {
			if (*__s1 == *__s2) {
				return (char*)__s1;
			}
		}
	}
	return S21_NULL;
}


char* s21_strrchr(const char* str, int c) {
	s21_size_t __ls = s21_strlen(str);
	s21_size_t __lr = 0;
	for (s21_size_t i = __ls; i >= 0; i--) {
		if (str[i] == c) {
			__lr = i;
			break;
		}
	}
	if (__lr == 0) {
		return S21_NULL;
	}
	char* __a = (char*)malloc(__ls - __lr + 1);
	if (__a == S21_NULL) {
		return S21_NULL;
	}
	for (s21_size_t i = 0; i < __ls - __lr; i++) {
		__a[i] = str[__lr + i];
	}
	__a[__ls - __lr] = '\0';
	return __a;
}


char* s21_strstr(const char* haystack, const char* needle) {
	s21_size_t __lh = s21_strlen(haystack);
	s21_size_t __ln = s21_strlen(needle);
	for (int i = 0; i < __lh; i++) {
		s21_size_t j;
		for (j = 0; j < __ln; j++) {
			if (haystack[i + j] != needle[j]) {
				break;
			}
		}
		if (j == __ln) {
			return (char*)(haystack + i);
		}
	}
	return S21_NULL;
}


char* s21_strtok(char* str, const char* delim) {
	static char* saveptr;
	char* token = str;
	if (str != S21_NULL) {
		while (*str && s21_strchr(delim, *str)) {
			str++;
		}
		token = str;
	} else {
		str = saveptr;
		if (str == S21_NULL) {
			return S21_NULL;
		}
		while (*str && s21_strchr(delim, *str)) {
			str++;
		}
	}
	token = str;
	while (*str && !s21_strchr(delim, *str)) {
		str++;
	}
	if (*str) {
		*str = '\0';
		saveptr = str + 1;
	} else {
		saveptr = S21_NULL;
	}
	return token;
}


void* s21_to_upper(const char* str) {
	if (str == S21_NULL) {
		return S21_NULL;
	}
	s21_size_t __l = s21_strlen(str);
	char* __a = (char*)malloc(__l + 1);
	if (__a == S21_NULL) {
		return S21_NULL;
	}
	for (s21_size_t i = 0; i < __l; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			__a[i] = str[i] - ('a' - 'A');
		}
		else {
			__a[i] = str[i];
		}
	}

	__a[__l] = '\0';
	return (void*)__a;
}


void* s21_to_lower(const char* str) {
	if (str == S21_NULL) {
		return S21_NULL;
	}
	s21_size_t __l = s21_strlen(str);
	char* __a = (char*)malloc(__l + 1);
	if (__a == S21_NULL) {
		return S21_NULL;
	}
	for (s21_size_t i = 0; i < __l; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			__a[i] = str[i] - ('A' - 'a');
		}
		else {
			__a[i] = str[i];
		}
	}

	__a[__l] = '\0';
	return (void*)__a;
}


void* s21_insert(const char* src, const char* str, s21_size_t start_index) {
	s21_size_t __lsrc = s21_strlen(src);
	s21_size_t __lstr = s21_strlen(str);
	char* __a = (char*)malloc(__lsrc + __lstr + 1);

	for (size_t i = 0; i < start_index; i++) {
		__a[i] = src[i];
	}
	for (size_t i = start_index, j = 0; j < __lstr; i++, j++) {
		__a[i] = str[j];
	}
	for (size_t i = start_index + __lstr, j = start_index; j < __lsrc; i++, j++) {
		__a[i] = src[j];
	}
	__a[__lsrc + __lstr] = '\0';
	return (void*)__a;
}


static int left_trim(const char* src, const char* trim_chars) {
	int flag = -1;
	for (int i = 0; src[i] != 0; i++) {
		int same = 0;
		for (int j = 0; trim_chars[j]; j++) {
			if (src[i] == trim_chars[j]) {
				same = 1;
			}
		}
		if (same != 1) {
			flag = i;
			break;
		}
	}
	return flag;
}


static int right_trim(const char* src, const char* trim_chars) {
	int flag = -1;
	s21_size_t i = s21_strlen(src) - 1;
	for (; i >= 0; i--) {
		int same = 0;
		for (int j = 0; trim_chars[j]; j++) {
			if (src[i] == trim_chars[j]) {
				same = 1;
			}
		}
		if (same != 1) {
			flag = i;
			break;
		}
	}
	return flag;
}


void* s21_trim(const char* src, const char* trim_chars) {
	int left = left_trim(src, trim_chars);
	int right = right_trim(src, trim_chars);
	char* cut = S21_NULL;
	if (right - left > 0) {
		cut = (char*)calloc(right - left, 1/8);
		if (cut != S21_NULL) {
			for (int k = 0; left <= right; left++, k++) cut[k] = src[left];
		}
	}
	return cut;
}