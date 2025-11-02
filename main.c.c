/// previous struct definition ///
#include "pico/multicore.h"
struct re_program;

/// struct definition ///
typedef char* string;

typedef __builtin_va_list va_list;

struct buffer
{
    char* buf;
    int len;
    int size;
};

struct sMemHeaderTiny
{
    unsigned int size;
    int allocated;
    struct sMemHeaderTiny* next;
    struct sMemHeaderTiny* prev;
    struct sMemHeaderTiny* free_next;
    char* class_name;
    char* sname;
    int sline;
};

struct sMemHeader
{
    unsigned int size;
    int allocated;
    struct sMemHeader* next;
    struct sMemHeader* prev;
    struct sMemHeader* free_next;
    char* class_name;
};

extern struct sMemHeader* gAllocMem;

extern int gComeDebugLib;

extern int gNumAlloc;

extern int gNumFree;

struct list_item$1char$
{
    char item;
    struct list_item$1char$* prev;
    struct list_item$1char$* next;
};

struct list$1char$
{
    struct list_item$1char$* head;
    struct list_item$1char$* tail;
    int len;
    struct list_item$1char$* it;
};

struct list_item$1char$p
{
    char* item;
    struct list_item$1char$p* prev;
    struct list_item$1char$p* next;
};

struct list$1char$p
{
    struct list_item$1char$p* head;
    struct list_item$1char$p* tail;
    int len;
    struct list_item$1char$p* it;
};

struct list_item$1short$
{
    short item;
    struct list_item$1short$* prev;
    struct list_item$1short$* next;
};

struct list$1short$
{
    struct list_item$1short$* head;
    struct list_item$1short$* tail;
    int len;
    struct list_item$1short$* it;
};

struct list_item$1int$
{
    int item;
    struct list_item$1int$* prev;
    struct list_item$1int$* next;
};

struct list$1int$
{
    struct list_item$1int$* head;
    struct list_item$1int$* tail;
    int len;
    struct list_item$1int$* it;
};

struct list_item$1long$
{
    long item;
    struct list_item$1long$* prev;
    struct list_item$1long$* next;
};

struct list$1long$
{
    struct list_item$1long$* head;
    struct list_item$1long$* tail;
    int len;
    struct list_item$1long$* it;
};

struct list_item$1float$
{
    float item;
    struct list_item$1float$* prev;
    struct list_item$1float$* next;
};

struct list$1float$
{
    struct list_item$1float$* head;
    struct list_item$1float$* tail;
    int len;
    struct list_item$1float$* it;
};

struct list_item$1double$
{
    double item;
    struct list_item$1double$* prev;
    struct list_item$1double$* next;
};

struct list$1double$
{
    struct list_item$1double$* head;
    struct list_item$1double$* tail;
    int len;
    struct list_item$1double$* it;
};

struct list_item$1char$ph
{
    char* item;
    struct list_item$1char$ph* prev;
    struct list_item$1char$ph* next;
};

struct list$1char$ph
{
    struct list_item$1char$ph* head;
    struct list_item$1char$ph* tail;
    int len;
    struct list_item$1char$ph* it;
};

typedef struct re_program* re_t;

struct re_capture
{
    int start;
    int length;
};

typedef struct re_capture re_capture;

enum { UNUSED
,DOT
,BEGIN
,END
,QUESTIONMARK
,STAR
,PLUS
,CHAR
,CHAR_CLASS
,INV_CHAR_CLASS
,DIGIT
,NOT_DIGIT
,ALPHA
,NOT_ALPHA
,WHITESPACE
,NOT_WHITESPACE
,GROUP
};

typedef struct regex_t regex_t;

struct anonymous_typeX14
{
    struct regex_t* first;
    int id;
};

union anonymous_typeZ13
{
unsigned char ch;
unsigned char* ccl;
struct anonymous_typeX14 group;
};

struct anonymous_typeX16
{
    struct regex_t* first;
    int id;
};

union anonymous_typeZ15
{
unsigned char ch;
unsigned char* ccl;
struct anonymous_typeX16 group;
};

struct regex_t
{
    unsigned char type;
    union anonymous_typeZ15 u;
    struct regex_t* next;
};

struct re_program
{
    struct regex_t* start;
    int group_count;
};

typedef struct re_program regex_program_t;

struct anonymous_typeX17
{
    struct regex_t* pool;
    int pool_capacity;
    int pool_size;
    unsigned char* ccl_buf;
    int ccl_capacity;
    int ccl_idx;
    int group_count;
};

typedef struct anonymous_typeX17 compiler_state;

struct anonymous_typeX18
{
    const char* base;
    struct re_capture* captures;
    int capture_capacity;
    int total_groups;
};

typedef struct anonymous_typeX18 match_context;

uint32_t SP;
uint32_t PC;
uint32_t R4;
uint32_t R5;
uint32_t R6;
uint32_t R7;
uint32_t R8;
uint32_t R9;
uint32_t R10;
uint32_t R11;
uint32_t* O;
uint32_t* P;
uint32_t* Q;
struct sTask
{
    uint32_t sp;
    uint32_t pc;
    uint32_t r4;
    uint32_t r5;
    uint32_t r6;
    uint32_t r7;
    uint32_t r8;
    uint32_t r9;
    uint32_t r10;
    uint32_t r11;
};

struct list_item$1sTask$ph
{
    struct sTask* item;
    struct list_item$1sTask$ph* prev;
    struct list_item$1sTask$ph* next;
};

struct list$1sTask$ph
{
    struct list_item$1sTask$ph* head;
    struct list_item$1sTask$ph* tail;
    int len;
    struct list_item$1sTask$ph* it;
};

struct list$1sTask$ph* gTasks;
int gCurrentTask=0;
// source head

// header function
void __retarget_lock_init(struct __lock** lock);
void __retarget_lock_init_recursive(struct __lock** lock);
void __retarget_lock_close(struct __lock* lock);
void __retarget_lock_close_recursive(struct __lock* lock);
void __retarget_lock_acquire(struct __lock* lock);
void __retarget_lock_acquire_recursive(struct __lock* lock);
int __retarget_lock_try_acquire(struct __lock* lock);
int __retarget_lock_try_acquire_recursive(struct __lock* lock);
void __retarget_lock_release(struct __lock* lock);
void __retarget_lock_release_recursive(struct __lock* lock);
void _reclaim_reent(struct _reent* anonymous_var_nameX33);
int _fwalk_sglue(struct _reent* anonymous_var_nameX34, int (*anonymous_lambda_var_nameZ1)(struct _reent*,struct __sFILE*), struct _glue* anonymous_var_nameX37);
int __locale_mb_cur_max();
void abort();
int abs(int anonymous_var_nameX40);
unsigned long  int arc4random();
unsigned long  int arc4random_uniform(unsigned long  int anonymous_var_nameX41);
void arc4random_buf(void* anonymous_var_nameX42, unsigned int anonymous_var_nameX43);
int atexit(void (*__func)());
double atof(const char* __nptr);
float atoff(const char* __nptr);
int atoi(const char* __nptr);
int _atoi_r(struct _reent* anonymous_var_nameX44, const char* __nptr);
long atol(const char* __nptr);
long _atol_r(struct _reent* anonymous_var_nameX45, const char* __nptr);
void* bsearch(const void* __key, const void* __base, unsigned int __nmemb, unsigned int __size, int (*_compar)(const void*,const void*));
void* calloc(unsigned int anonymous_var_nameX46, unsigned int anonymous_var_nameX47);
struct anonymous_typeX9 div(int __numer, int __denom);
void exit(int __status);
void free(void* anonymous_var_nameX48);
char* getenv(const char* __string);
char* _getenv_r(struct _reent* anonymous_var_nameX49, const char* __string);
char* secure_getenv(const char* __string);
char* _findenv(const char* anonymous_var_nameX50, int* anonymous_var_nameX51);
char* _findenv_r(struct _reent* anonymous_var_nameX52, const char* anonymous_var_nameX53, int* anonymous_var_nameX54);
int getsubopt(char** anonymous_var_nameX55, char** anonymous_var_nameX56, char** anonymous_var_nameX57);
long labs(long anonymous_var_nameX58);
struct anonymous_typeX10 ldiv(long __numer, long __denom);
void* malloc(unsigned int anonymous_var_nameX59);
int mblen(const char* anonymous_var_nameX60, unsigned int anonymous_var_nameX61);
int _mblen_r(struct _reent* anonymous_var_nameX62, const char* anonymous_var_nameX63, unsigned int anonymous_var_nameX64, struct anonymous_typeX2* anonymous_var_nameX65);
int mbtowc(unsigned int* anonymous_var_nameX66, const char* anonymous_var_nameX67, unsigned int anonymous_var_nameX68);
int _mbtowc_r(struct _reent* anonymous_var_nameX69, unsigned int* anonymous_var_nameX70, const char* anonymous_var_nameX71, unsigned int anonymous_var_nameX72, struct anonymous_typeX2* anonymous_var_nameX73);
int wctomb(char* anonymous_var_nameX74, unsigned int anonymous_var_nameX75);
int _wctomb_r(struct _reent* anonymous_var_nameX76, char* anonymous_var_nameX77, unsigned int anonymous_var_nameX78, struct anonymous_typeX2* anonymous_var_nameX79);
unsigned int mbstowcs(unsigned int* anonymous_var_nameX80, const char* anonymous_var_nameX81, unsigned int anonymous_var_nameX82);
unsigned int _mbstowcs_r(struct _reent* anonymous_var_nameX83, unsigned int* anonymous_var_nameX84, const char* anonymous_var_nameX85, unsigned int anonymous_var_nameX86, struct anonymous_typeX2* anonymous_var_nameX87);
unsigned int wcstombs(char* anonymous_var_nameX88, const unsigned int* anonymous_var_nameX89, unsigned int anonymous_var_nameX90);
unsigned int _wcstombs_r(struct _reent* anonymous_var_nameX91, char* anonymous_var_nameX92, const unsigned int* anonymous_var_nameX93, unsigned int anonymous_var_nameX94, struct anonymous_typeX2* anonymous_var_nameX95);
char* mkdtemp(char* anonymous_var_nameX96);
int mkostemp(char* anonymous_var_nameX97, int anonymous_var_nameX98);
int mkostemps(char* anonymous_var_nameX99, int anonymous_var_nameX100, int anonymous_var_nameX101);
int mkstemp(char* anonymous_var_nameX102);
int mkstemps(char* anonymous_var_nameX103, int anonymous_var_nameX104);
char* mktemp(char* anonymous_var_nameX105);
char* _mkdtemp_r(struct _reent* anonymous_var_nameX106, char* anonymous_var_nameX107);
int _mkostemp_r(struct _reent* anonymous_var_nameX108, char* anonymous_var_nameX109, int anonymous_var_nameX110);
int _mkostemps_r(struct _reent* anonymous_var_nameX111, char* anonymous_var_nameX112, int anonymous_var_nameX113, int anonymous_var_nameX114);
int _mkstemp_r(struct _reent* anonymous_var_nameX115, char* anonymous_var_nameX116);
int _mkstemps_r(struct _reent* anonymous_var_nameX117, char* anonymous_var_nameX118, int anonymous_var_nameX119);
char* _mktemp_r(struct _reent* anonymous_var_nameX120, char* anonymous_var_nameX121);
void qsort(void* __base, unsigned int __nmemb, unsigned int __size, int (*_compar)(const void*,const void*));
int rand();
void* realloc(void* anonymous_var_nameX122, unsigned int anonymous_var_nameX123);
void* reallocarray(void* anonymous_var_nameX124, unsigned int anonymous_var_nameX125, unsigned int anonymous_var_nameX126);
void* reallocf(void* anonymous_var_nameX127, unsigned int anonymous_var_nameX128);
char* realpath(const char* path, char* resolved_path);
int rpmatch(const char* response);
void setkey(const char* __key);
void srand(unsigned int __seed);
double strtod(const char* __n, char** __end_PTR);
double _strtod_r(struct _reent* anonymous_var_nameX129, const char* __n, char** __end_PTR);
float strtof(const char* __n, char** __end_PTR);
long strtol(const char* __n, char** __end_PTR, int __base);
long _strtol_r(struct _reent* anonymous_var_nameX130, const char* __n, char** __end_PTR, int __base);
unsigned long  int strtoul(const char* __n, char** __end_PTR, int __base);
unsigned long  int _strtoul_r(struct _reent* anonymous_var_nameX131, const char* __n, char** __end_PTR, int __base);
double strtod_l(const char* anonymous_var_nameX132, char** anonymous_var_nameX133, struct __locale_t* anonymous_var_nameX134);
float strtof_l(const char* anonymous_var_nameX135, char** anonymous_var_nameX136, struct __locale_t* anonymous_var_nameX137);
long  double strtold_l(const char* anonymous_var_nameX138, char** anonymous_var_nameX139, struct __locale_t* anonymous_var_nameX140);
long strtol_l(const char* anonymous_var_nameX141, char** anonymous_var_nameX142, int anonymous_var_nameX143, struct __locale_t* anonymous_var_nameX144);
unsigned long  int strtoul_l(const char* anonymous_var_nameX145, char** anonymous_var_nameX146, int anonymous_var_nameX147, struct __locale_t* __loc);
long long strtoll_l(const char* anonymous_var_nameX148, char** anonymous_var_nameX149, int anonymous_var_nameX150, struct __locale_t* anonymous_var_nameX151);
unsigned long  long strtoull_l(const char* anonymous_var_nameX152, char** anonymous_var_nameX153, int anonymous_var_nameX154, struct __locale_t* __loc);
int system(const char* __string);
long a64l(const char* __input);
char* l64a(long __input);
char* _l64a_r(struct _reent* anonymous_var_nameX155, long __input);
int on_exit(void (*__func)(int,void*), void* __arg);
void _Exit(int __status);
int putenv(char* __string);
int _putenv_r(struct _reent* anonymous_var_nameX158, char* __string);
void* _reallocf_r(struct _reent* anonymous_var_nameX159, void* anonymous_var_nameX160, unsigned int anonymous_var_nameX161);
int setenv(const char* __string, const char* __value, int __overwrite);
int _setenv_r(struct _reent* anonymous_var_nameX162, const char* __string, const char* __value, int __overwrite);
char* __itoa(int anonymous_var_nameX163, char* anonymous_var_nameX164, int anonymous_var_nameX165);
char* __utoa(unsigned int anonymous_var_nameX166, char* anonymous_var_nameX167, int anonymous_var_nameX168);
char* itoa(int anonymous_var_nameX169, char* anonymous_var_nameX170, int anonymous_var_nameX171);
char* utoa(unsigned int anonymous_var_nameX172, char* anonymous_var_nameX173, int anonymous_var_nameX174);
int rand_r(unsigned int* __seed);
double drand48();
double _drand48_r(struct _reent* anonymous_var_nameX175);
double erand48(unsigned short int anonymous_var_nameX176[3]);
double _erand48_r(struct _reent* anonymous_var_nameX177, unsigned short int anonymous_var_nameX178[3]);
long jrand48(unsigned short int anonymous_var_nameX179[3]);
long _jrand48_r(struct _reent* anonymous_var_nameX180, unsigned short int anonymous_var_nameX181[3]);
void lcong48(unsigned short int anonymous_var_nameX182[7]);
void _lcong48_r(struct _reent* anonymous_var_nameX183, unsigned short int anonymous_var_nameX184[7]);
long lrand48();
long _lrand48_r(struct _reent* anonymous_var_nameX185);
long mrand48();
long _mrand48_r(struct _reent* anonymous_var_nameX186);
long nrand48(unsigned short int anonymous_var_nameX187[3]);
long _nrand48_r(struct _reent* anonymous_var_nameX188, unsigned short int anonymous_var_nameX189[3]);
unsigned short int* seed48(unsigned short int anonymous_var_nameX190[3]);
unsigned short int* _seed48_r(struct _reent* anonymous_var_nameX191, unsigned short int anonymous_var_nameX192[3]);
void srand48(long anonymous_var_nameX193);
void _srand48_r(struct _reent* anonymous_var_nameX194, long anonymous_var_nameX195);
char* initstate(unsigned int anonymous_var_nameX196, char* anonymous_var_nameX197, unsigned int anonymous_var_nameX198);
long random();
char* setstate(char* anonymous_var_nameX199);
void srandom(unsigned int anonymous_var_nameX200);
long long atoll(const char* __nptr);
long long _atoll_r(struct _reent* anonymous_var_nameX201, const char* __nptr);
long long llabs(long  long anonymous_var_nameX202);
struct anonymous_typeX11 lldiv(long long __numer, long long __denom);
long long strtoll(const char* __n, char** __end_PTR, int __base);
long long _strtoll_r(struct _reent* anonymous_var_nameX203, const char* __n, char** __end_PTR, int __base);
unsigned long  long strtoull(const char* __n, char** __end_PTR, int __base);
unsigned long  long _strtoull_r(struct _reent* anonymous_var_nameX204, const char* __n, char** __end_PTR, int __base);
void cfree(void* anonymous_var_nameX205);
int unsetenv(const char* __string);
int _unsetenv_r(struct _reent* anonymous_var_nameX206, const char* __string);
int posix_memalign(void** anonymous_var_nameX207, unsigned int anonymous_var_nameX208, unsigned int anonymous_var_nameX209);
char* _dtoa_r(struct _reent* anonymous_var_nameX210, double anonymous_var_nameX211, int anonymous_var_nameX212, int anonymous_var_nameX213, int* anonymous_var_nameX214, int* anonymous_var_nameX215, char** anonymous_var_nameX216);
void* _malloc_r(struct _reent* anonymous_var_nameX217, unsigned int anonymous_var_nameX218);
void* _calloc_r(struct _reent* anonymous_var_nameX219, unsigned int anonymous_var_nameX220, unsigned int anonymous_var_nameX221);
void _free_r(struct _reent* anonymous_var_nameX222, void* anonymous_var_nameX223);
void* _realloc_r(struct _reent* anonymous_var_nameX224, void* anonymous_var_nameX225, unsigned int anonymous_var_nameX226);
void _mstats_r(struct _reent* anonymous_var_nameX227, char* anonymous_var_nameX228);
int _system_r(struct _reent* anonymous_var_nameX229, const char* anonymous_var_nameX230);
void __eprintf(const char* anonymous_var_nameX231, const char* anonymous_var_nameX232, unsigned int anonymous_var_nameX233, const char* anonymous_var_nameX234);
void qsort_r(void* __base, unsigned int __nmemb, unsigned int __size, int (*_compar)(const void*,const void*,void*), void* __thunk);
long  double _strtold_r(struct _reent* anonymous_var_nameX238, const char* anonymous_var_nameX239, char** anonymous_var_nameX240);
long  double strtold(const char* anonymous_var_nameX241, char** anonymous_var_nameX242);
void* aligned_alloc(unsigned int anonymous_var_nameX243, unsigned int anonymous_var_nameX244);
int at_quick_exit(void (*anonymous_lambda_var_nameZ2)());
void quick_exit(int anonymous_var_nameX245);
char* ctermid(char* anonymous_var_nameX246);
char* cuserid(char* anonymous_var_nameX247);
struct __sFILE* tmpfile();
char* tmpnam(char* anonymous_var_nameX248);
char* tempnam(const char* anonymous_var_nameX249, const char* anonymous_var_nameX250);
int fclose(struct __sFILE* anonymous_var_nameX251);
int fflush(struct __sFILE* anonymous_var_nameX252);
struct __sFILE* freopen(const char* anonymous_var_nameX253, const char* anonymous_var_nameX254, struct __sFILE* anonymous_var_nameX255);
void setbuf(struct __sFILE* anonymous_var_nameX256, char* anonymous_var_nameX257);
int setvbuf(struct __sFILE* anonymous_var_nameX258, char* anonymous_var_nameX259, int anonymous_var_nameX260, unsigned int anonymous_var_nameX261);
int fprintf(struct __sFILE* anonymous_var_nameX262, const char* anonymous_var_nameX263, ...);
int fscanf(struct __sFILE* anonymous_var_nameX264, const char* anonymous_var_nameX265, ...);
int printf(const char* anonymous_var_nameX266, ...);
int scanf(const char* anonymous_var_nameX267, ...);
int sscanf(const char* anonymous_var_nameX268, const char* anonymous_var_nameX269, ...);
int vfprintf(struct __sFILE* anonymous_var_nameX270, const char* anonymous_var_nameX271, va_list anonymous_var_nameX272);
int vprintf(const char* anonymous_var_nameX273, va_list anonymous_var_nameX274);
int vsprintf(char* anonymous_var_nameX275, const char* anonymous_var_nameX276, va_list anonymous_var_nameX277);
int fgetc(struct __sFILE* anonymous_var_nameX278);
char* fgets(char* anonymous_var_nameX279, int anonymous_var_nameX280, struct __sFILE* anonymous_var_nameX281);
int fputc(int anonymous_var_nameX282, struct __sFILE* anonymous_var_nameX283);
int fputs(const char* anonymous_var_nameX284, struct __sFILE* anonymous_var_nameX285);
int getc(struct __sFILE* anonymous_var_nameX286);
int getchar();
char* gets(char* anonymous_var_nameX287);
int putc(int anonymous_var_nameX288, struct __sFILE* anonymous_var_nameX289);
int puts(const char* anonymous_var_nameX291);
int ungetc(int anonymous_var_nameX292, struct __sFILE* anonymous_var_nameX293);
unsigned int fread(void* anonymous_var_nameX294, unsigned int _size, unsigned int _n, struct __sFILE* anonymous_var_nameX295);
unsigned int fwrite(const void* anonymous_var_nameX296, unsigned int _size, unsigned int _n, struct __sFILE* anonymous_var_nameX297);
int fgetpos(struct __sFILE* anonymous_var_nameX298, long* anonymous_var_nameX299);
int fseek(struct __sFILE* anonymous_var_nameX300, long anonymous_var_nameX301, int anonymous_var_nameX302);
int fsetpos(struct __sFILE* anonymous_var_nameX303, const long* anonymous_var_nameX304);
long ftell(struct __sFILE* anonymous_var_nameX305);
void rewind(struct __sFILE* anonymous_var_nameX306);
void clearerr(struct __sFILE* anonymous_var_nameX307);
int feof(struct __sFILE* anonymous_var_nameX308);
int ferror(struct __sFILE* anonymous_var_nameX309);
void perror(const char* anonymous_var_nameX310);
struct __sFILE* fopen(const char* _name, const char* _type);
int sprintf(char* anonymous_var_nameX311, const char* anonymous_var_nameX312, ...);
int remove(const char* anonymous_var_nameX313);
int rename(const char* anonymous_var_nameX314, const char* anonymous_var_nameX315);
int fseeko(struct __sFILE* anonymous_var_nameX316, long anonymous_var_nameX317, int anonymous_var_nameX318);
long ftello(struct __sFILE* anonymous_var_nameX319);
int fcloseall();
int snprintf(char* anonymous_var_nameX320, unsigned int anonymous_var_nameX321, const char* anonymous_var_nameX322, ...);
int vsnprintf(char* anonymous_var_nameX323, unsigned int anonymous_var_nameX324, const char* anonymous_var_nameX325, va_list anonymous_var_nameX326);
int vfscanf(struct __sFILE* anonymous_var_nameX327, const char* anonymous_var_nameX328, va_list anonymous_var_nameX329);
int vscanf(const char* anonymous_var_nameX330, va_list anonymous_var_nameX331);
int vsscanf(const char* anonymous_var_nameX332, const char* anonymous_var_nameX333, va_list anonymous_var_nameX334);
int asprintf(char** anonymous_var_nameX335, const char* anonymous_var_nameX336, ...);
int vasprintf(char** anonymous_var_nameX337, const char* anonymous_var_nameX338, va_list anonymous_var_nameX339);
int asiprintf(char** anonymous_var_nameX340, const char* anonymous_var_nameX341, ...);
char* asniprintf(char* anonymous_var_nameX342, unsigned int* anonymous_var_nameX343, const char* anonymous_var_nameX344, ...);
char* asnprintf(char* anonymous_var_nameX345, unsigned int* anonymous_var_nameX346, const char* anonymous_var_nameX347, ...);
int diprintf(int anonymous_var_nameX348, const char* anonymous_var_nameX349, ...);
int fiprintf(struct __sFILE* anonymous_var_nameX350, const char* anonymous_var_nameX351, ...);
int fiscanf(struct __sFILE* anonymous_var_nameX352, const char* anonymous_var_nameX353, ...);
int iprintf(const char* anonymous_var_nameX354, ...);
int iscanf(const char* anonymous_var_nameX355, ...);
int siprintf(char* anonymous_var_nameX356, const char* anonymous_var_nameX357, ...);
int siscanf(const char* anonymous_var_nameX358, const char* anonymous_var_nameX359, ...);
int sniprintf(char* anonymous_var_nameX360, unsigned int anonymous_var_nameX361, const char* anonymous_var_nameX362, ...);
int vasiprintf(char** anonymous_var_nameX363, const char* anonymous_var_nameX364, va_list anonymous_var_nameX365);
char* vasniprintf(char* anonymous_var_nameX366, unsigned int* anonymous_var_nameX367, const char* anonymous_var_nameX368, va_list anonymous_var_nameX369);
char* vasnprintf(char* anonymous_var_nameX370, unsigned int* anonymous_var_nameX371, const char* anonymous_var_nameX372, va_list anonymous_var_nameX373);
int vdiprintf(int anonymous_var_nameX374, const char* anonymous_var_nameX375, va_list anonymous_var_nameX376);
int vfiprintf(struct __sFILE* anonymous_var_nameX377, const char* anonymous_var_nameX378, va_list anonymous_var_nameX379);
int vfiscanf(struct __sFILE* anonymous_var_nameX380, const char* anonymous_var_nameX381, va_list anonymous_var_nameX382);
int viprintf(const char* anonymous_var_nameX383, va_list anonymous_var_nameX384);
int viscanf(const char* anonymous_var_nameX385, va_list anonymous_var_nameX386);
int vsiprintf(char* anonymous_var_nameX387, const char* anonymous_var_nameX388, va_list anonymous_var_nameX389);
int vsiscanf(const char* anonymous_var_nameX390, const char* anonymous_var_nameX391, va_list anonymous_var_nameX392);
int vsniprintf(char* anonymous_var_nameX393, unsigned int anonymous_var_nameX394, const char* anonymous_var_nameX395, va_list anonymous_var_nameX396);
struct __sFILE* fdopen(int anonymous_var_nameX397, const char* anonymous_var_nameX398);
int fileno(struct __sFILE* anonymous_var_nameX399);
int pclose(struct __sFILE* anonymous_var_nameX400);
struct __sFILE* popen(const char* anonymous_var_nameX401, const char* anonymous_var_nameX402);
void setbuffer(struct __sFILE* anonymous_var_nameX403, char* anonymous_var_nameX404, int anonymous_var_nameX405);
int setlinebuf(struct __sFILE* anonymous_var_nameX406);
int getw(struct __sFILE* anonymous_var_nameX407);
int putw(int anonymous_var_nameX408, struct __sFILE* anonymous_var_nameX409);
int getc_unlocked(struct __sFILE* anonymous_var_nameX410);
int getchar_unlocked();
void flockfile(struct __sFILE* anonymous_var_nameX411);
int ftrylockfile(struct __sFILE* anonymous_var_nameX412);
void funlockfile(struct __sFILE* anonymous_var_nameX413);
int putc_unlocked(int anonymous_var_nameX414, struct __sFILE* anonymous_var_nameX415);
int putchar_unlocked(int anonymous_var_nameX416);
int dprintf(int anonymous_var_nameX417, const char* anonymous_var_nameX418, ...);
struct __sFILE* fmemopen(void* anonymous_var_nameX419, unsigned int anonymous_var_nameX420, const char* anonymous_var_nameX421);
struct __sFILE* open_memstream(char** anonymous_var_nameX422, unsigned int* anonymous_var_nameX423);
int vdprintf(int anonymous_var_nameX424, const char* anonymous_var_nameX425, va_list anonymous_var_nameX426);
int renameat(int anonymous_var_nameX427, const char* anonymous_var_nameX428, int anonymous_var_nameX429, const char* anonymous_var_nameX430);
int _asiprintf_r(struct _reent* anonymous_var_nameX431, char** anonymous_var_nameX432, const char* anonymous_var_nameX433, ...);
char* _asniprintf_r(struct _reent* anonymous_var_nameX434, char* anonymous_var_nameX435, unsigned int* anonymous_var_nameX436, const char* anonymous_var_nameX437, ...);
char* _asnprintf_r(struct _reent* anonymous_var_nameX438, char* anonymous_var_nameX439, unsigned int* anonymous_var_nameX440, const char* anonymous_var_nameX441, ...);
int _asprintf_r(struct _reent* anonymous_var_nameX442, char** anonymous_var_nameX443, const char* anonymous_var_nameX444, ...);
int _diprintf_r(struct _reent* anonymous_var_nameX445, int anonymous_var_nameX446, const char* anonymous_var_nameX447, ...);
int _dprintf_r(struct _reent* anonymous_var_nameX448, int anonymous_var_nameX449, const char* anonymous_var_nameX450, ...);
int _fclose_r(struct _reent* anonymous_var_nameX451, struct __sFILE* anonymous_var_nameX452);
int _fcloseall_r(struct _reent* anonymous_var_nameX453);
struct __sFILE* _fdopen_r(struct _reent* anonymous_var_nameX454, int anonymous_var_nameX455, const char* anonymous_var_nameX456);
int _fflush_r(struct _reent* anonymous_var_nameX457, struct __sFILE* anonymous_var_nameX458);
int _fgetc_r(struct _reent* anonymous_var_nameX459, struct __sFILE* anonymous_var_nameX460);
int _fgetc_unlocked_r(struct _reent* anonymous_var_nameX461, struct __sFILE* anonymous_var_nameX462);
char* _fgets_r(struct _reent* anonymous_var_nameX463, char* anonymous_var_nameX464, int anonymous_var_nameX465, struct __sFILE* anonymous_var_nameX466);
char* _fgets_unlocked_r(struct _reent* anonymous_var_nameX467, char* anonymous_var_nameX468, int anonymous_var_nameX469, struct __sFILE* anonymous_var_nameX470);
int _fgetpos_r(struct _reent* anonymous_var_nameX471, struct __sFILE* anonymous_var_nameX472, long* anonymous_var_nameX473);
int _fsetpos_r(struct _reent* anonymous_var_nameX474, struct __sFILE* anonymous_var_nameX475, const long* anonymous_var_nameX476);
int _fiprintf_r(struct _reent* anonymous_var_nameX477, struct __sFILE* anonymous_var_nameX478, const char* anonymous_var_nameX479, ...);
int _fiscanf_r(struct _reent* anonymous_var_nameX480, struct __sFILE* anonymous_var_nameX481, const char* anonymous_var_nameX482, ...);
struct __sFILE* _fmemopen_r(struct _reent* anonymous_var_nameX483, void* anonymous_var_nameX484, unsigned int anonymous_var_nameX485, const char* anonymous_var_nameX486);
struct __sFILE* _fopen_r(struct _reent* anonymous_var_nameX487, const char* anonymous_var_nameX488, const char* anonymous_var_nameX489);
struct __sFILE* _freopen_r(struct _reent* anonymous_var_nameX490, const char* anonymous_var_nameX491, const char* anonymous_var_nameX492, struct __sFILE* anonymous_var_nameX493);
int _fprintf_r(struct _reent* anonymous_var_nameX494, struct __sFILE* anonymous_var_nameX495, const char* anonymous_var_nameX496, ...);
int _fpurge_r(struct _reent* anonymous_var_nameX497, struct __sFILE* anonymous_var_nameX498);
int _fputc_r(struct _reent* anonymous_var_nameX499, int anonymous_var_nameX500, struct __sFILE* anonymous_var_nameX501);
int _fputc_unlocked_r(struct _reent* anonymous_var_nameX502, int anonymous_var_nameX503, struct __sFILE* anonymous_var_nameX504);
int _fputs_r(struct _reent* anonymous_var_nameX505, const char* anonymous_var_nameX506, struct __sFILE* anonymous_var_nameX507);
int _fputs_unlocked_r(struct _reent* anonymous_var_nameX508, const char* anonymous_var_nameX509, struct __sFILE* anonymous_var_nameX510);
unsigned int _fread_r(struct _reent* anonymous_var_nameX511, void* anonymous_var_nameX512, unsigned int _size, unsigned int _n, struct __sFILE* anonymous_var_nameX513);
unsigned int _fread_unlocked_r(struct _reent* anonymous_var_nameX514, void* anonymous_var_nameX515, unsigned int _size, unsigned int _n, struct __sFILE* anonymous_var_nameX516);
int _fscanf_r(struct _reent* anonymous_var_nameX517, struct __sFILE* anonymous_var_nameX518, const char* anonymous_var_nameX519, ...);
int _fseek_r(struct _reent* anonymous_var_nameX520, struct __sFILE* anonymous_var_nameX521, long anonymous_var_nameX522, int anonymous_var_nameX523);
int _fseeko_r(struct _reent* anonymous_var_nameX524, struct __sFILE* anonymous_var_nameX525, long anonymous_var_nameX526, int anonymous_var_nameX527);
long _ftell_r(struct _reent* anonymous_var_nameX528, struct __sFILE* anonymous_var_nameX529);
long _ftello_r(struct _reent* anonymous_var_nameX530, struct __sFILE* anonymous_var_nameX531);
void _rewind_r(struct _reent* anonymous_var_nameX532, struct __sFILE* anonymous_var_nameX533);
unsigned int _fwrite_r(struct _reent* anonymous_var_nameX534, const void* anonymous_var_nameX535, unsigned int _size, unsigned int _n, struct __sFILE* anonymous_var_nameX536);
unsigned int _fwrite_unlocked_r(struct _reent* anonymous_var_nameX537, const void* anonymous_var_nameX538, unsigned int _size, unsigned int _n, struct __sFILE* anonymous_var_nameX539);
int _getc_r(struct _reent* anonymous_var_nameX540, struct __sFILE* anonymous_var_nameX541);
int _getc_unlocked_r(struct _reent* anonymous_var_nameX542, struct __sFILE* anonymous_var_nameX543);
int _getchar_r(struct _reent* anonymous_var_nameX544);
int _getchar_unlocked_r(struct _reent* anonymous_var_nameX545);
char* _gets_r(struct _reent* anonymous_var_nameX546, char* anonymous_var_nameX547);
int _iprintf_r(struct _reent* anonymous_var_nameX548, const char* anonymous_var_nameX549, ...);
int _iscanf_r(struct _reent* anonymous_var_nameX550, const char* anonymous_var_nameX551, ...);
struct __sFILE* _open_memstream_r(struct _reent* anonymous_var_nameX552, char** anonymous_var_nameX553, unsigned int* anonymous_var_nameX554);
void _perror_r(struct _reent* anonymous_var_nameX555, const char* anonymous_var_nameX556);
int _printf_r(struct _reent* anonymous_var_nameX557, const char* anonymous_var_nameX558, ...);
int _putc_r(struct _reent* anonymous_var_nameX559, int anonymous_var_nameX560, struct __sFILE* anonymous_var_nameX561);
int _putc_unlocked_r(struct _reent* anonymous_var_nameX562, int anonymous_var_nameX563, struct __sFILE* anonymous_var_nameX564);
int _putchar_unlocked_r(struct _reent* anonymous_var_nameX565, int anonymous_var_nameX566);
int _putchar_r(struct _reent* anonymous_var_nameX567, int anonymous_var_nameX568);
int _puts_r(struct _reent* anonymous_var_nameX569, const char* anonymous_var_nameX570);
int _remove_r(struct _reent* anonymous_var_nameX571, const char* anonymous_var_nameX572);
int _rename_r(struct _reent* anonymous_var_nameX573, const char* _old, const char* _new);
int _scanf_r(struct _reent* anonymous_var_nameX574, const char* anonymous_var_nameX575, ...);
int _siprintf_r(struct _reent* anonymous_var_nameX576, char* anonymous_var_nameX577, const char* anonymous_var_nameX578, ...);
int _siscanf_r(struct _reent* anonymous_var_nameX579, const char* anonymous_var_nameX580, const char* anonymous_var_nameX581, ...);
int _sniprintf_r(struct _reent* anonymous_var_nameX582, char* anonymous_var_nameX583, unsigned int anonymous_var_nameX584, const char* anonymous_var_nameX585, ...);
int _snprintf_r(struct _reent* anonymous_var_nameX586, char* anonymous_var_nameX587, unsigned int anonymous_var_nameX588, const char* anonymous_var_nameX589, ...);
int _sprintf_r(struct _reent* anonymous_var_nameX590, char* anonymous_var_nameX591, const char* anonymous_var_nameX592, ...);
int _sscanf_r(struct _reent* anonymous_var_nameX593, const char* anonymous_var_nameX594, const char* anonymous_var_nameX595, ...);
char* _tempnam_r(struct _reent* anonymous_var_nameX596, const char* anonymous_var_nameX597, const char* anonymous_var_nameX598);
struct __sFILE* _tmpfile_r(struct _reent* anonymous_var_nameX599);
char* _tmpnam_r(struct _reent* anonymous_var_nameX600, char* anonymous_var_nameX601);
int _ungetc_r(struct _reent* anonymous_var_nameX602, int anonymous_var_nameX603, struct __sFILE* anonymous_var_nameX604);
int _vasiprintf_r(struct _reent* anonymous_var_nameX605, char** anonymous_var_nameX606, const char* anonymous_var_nameX607, va_list anonymous_var_nameX608);
char* _vasniprintf_r(struct _reent* anonymous_var_nameX609, char* anonymous_var_nameX610, unsigned int* anonymous_var_nameX611, const char* anonymous_var_nameX612, va_list anonymous_var_nameX613);
char* _vasnprintf_r(struct _reent* anonymous_var_nameX614, char* anonymous_var_nameX615, unsigned int* anonymous_var_nameX616, const char* anonymous_var_nameX617, va_list anonymous_var_nameX618);
int _vasprintf_r(struct _reent* anonymous_var_nameX619, char** anonymous_var_nameX620, const char* anonymous_var_nameX621, va_list anonymous_var_nameX622);
int _vdiprintf_r(struct _reent* anonymous_var_nameX623, int anonymous_var_nameX624, const char* anonymous_var_nameX625, va_list anonymous_var_nameX626);
int _vdprintf_r(struct _reent* anonymous_var_nameX627, int anonymous_var_nameX628, const char* anonymous_var_nameX629, va_list anonymous_var_nameX630);
int _vfiprintf_r(struct _reent* anonymous_var_nameX631, struct __sFILE* anonymous_var_nameX632, const char* anonymous_var_nameX633, va_list anonymous_var_nameX634);
int _vfiscanf_r(struct _reent* anonymous_var_nameX635, struct __sFILE* anonymous_var_nameX636, const char* anonymous_var_nameX637, va_list anonymous_var_nameX638);
int _vfprintf_r(struct _reent* anonymous_var_nameX639, struct __sFILE* anonymous_var_nameX640, const char* anonymous_var_nameX641, va_list anonymous_var_nameX642);
int _vfscanf_r(struct _reent* anonymous_var_nameX643, struct __sFILE* anonymous_var_nameX644, const char* anonymous_var_nameX645, va_list anonymous_var_nameX646);
int _viprintf_r(struct _reent* anonymous_var_nameX647, const char* anonymous_var_nameX648, va_list anonymous_var_nameX649);
int _viscanf_r(struct _reent* anonymous_var_nameX650, const char* anonymous_var_nameX651, va_list anonymous_var_nameX652);
int _vprintf_r(struct _reent* anonymous_var_nameX653, const char* anonymous_var_nameX654, va_list anonymous_var_nameX655);
int _vscanf_r(struct _reent* anonymous_var_nameX656, const char* anonymous_var_nameX657, va_list anonymous_var_nameX658);
int _vsiprintf_r(struct _reent* anonymous_var_nameX659, char* anonymous_var_nameX660, const char* anonymous_var_nameX661, va_list anonymous_var_nameX662);
int _vsiscanf_r(struct _reent* anonymous_var_nameX663, const char* anonymous_var_nameX664, const char* anonymous_var_nameX665, va_list anonymous_var_nameX666);
int _vsniprintf_r(struct _reent* anonymous_var_nameX667, char* anonymous_var_nameX668, unsigned int anonymous_var_nameX669, const char* anonymous_var_nameX670, va_list anonymous_var_nameX671);
int _vsnprintf_r(struct _reent* anonymous_var_nameX672, char* anonymous_var_nameX673, unsigned int anonymous_var_nameX674, const char* anonymous_var_nameX675, va_list anonymous_var_nameX676);
int _vsprintf_r(struct _reent* anonymous_var_nameX677, char* anonymous_var_nameX678, const char* anonymous_var_nameX679, va_list anonymous_var_nameX680);
int _vsscanf_r(struct _reent* anonymous_var_nameX681, const char* anonymous_var_nameX682, const char* anonymous_var_nameX683, va_list anonymous_var_nameX684);
int fpurge(struct __sFILE* anonymous_var_nameX685);
int __getdelim(char** anonymous_var_nameX686, unsigned int* anonymous_var_nameX687, int anonymous_var_nameX688, struct __sFILE* anonymous_var_nameX689);
int __getline(char** anonymous_var_nameX690, unsigned int* anonymous_var_nameX691, struct __sFILE* anonymous_var_nameX692);
void clearerr_unlocked(struct __sFILE* anonymous_var_nameX693);
int feof_unlocked(struct __sFILE* anonymous_var_nameX694);
int ferror_unlocked(struct __sFILE* anonymous_var_nameX695);
int fileno_unlocked(struct __sFILE* anonymous_var_nameX696);
int fflush_unlocked(struct __sFILE* anonymous_var_nameX697);
int fgetc_unlocked(struct __sFILE* anonymous_var_nameX698);
int fputc_unlocked(int anonymous_var_nameX699, struct __sFILE* anonymous_var_nameX700);
unsigned int fread_unlocked(void* anonymous_var_nameX701, unsigned int _size, unsigned int _n, struct __sFILE* anonymous_var_nameX702);
unsigned int fwrite_unlocked(const void* anonymous_var_nameX703, unsigned int _size, unsigned int _n, struct __sFILE* anonymous_var_nameX704);
char* fgets_unlocked(char* anonymous_var_nameX705, int anonymous_var_nameX706, struct __sFILE* anonymous_var_nameX707);
int fputs_unlocked(const char* anonymous_var_nameX708, struct __sFILE* anonymous_var_nameX709);
int __srget_r(struct _reent* anonymous_var_nameX710, struct __sFILE* anonymous_var_nameX711);
int __swbuf_r(struct _reent* anonymous_var_nameX712, int anonymous_var_nameX713, struct __sFILE* anonymous_var_nameX714);
struct __sFILE* funopen(const void* __cookie, int (*__readfn)(void*,char*,int), int (*__writefn)(void*,const char*,int), long (*__seekfn)(void*,long,int), int (*__closefn)(void*));
struct __sFILE* _funopen_r(struct _reent* anonymous_var_nameX715, const void* __cookie, int (*__readfn)(void*,char*,int), int (*__writefn)(void*,const char*,int), long (*__seekfn)(void*,long,int), int (*__closefn)(void*));
struct __sFILE* fopencookie(void* __cookie, const char* __mode, struct anonymous_typeX12 __functions);
struct __sFILE* _fopencookie_r(struct _reent* anonymous_var_nameX716, void* __cookie, const char* __mode, struct anonymous_typeX12 __functions);
int bcmp(const void* anonymous_var_nameX717, const void* anonymous_var_nameX718, unsigned int anonymous_var_nameX719);
void bcopy(const void* anonymous_var_nameX720, void* anonymous_var_nameX721, unsigned int anonymous_var_nameX722);
void bzero(void* anonymous_var_nameX723, unsigned int anonymous_var_nameX724);
void explicit_bzero(void* anonymous_var_nameX725, unsigned int anonymous_var_nameX726);
int ffs(int anonymous_var_nameX727);
int ffsl(long anonymous_var_nameX728);
int ffsll(long  long anonymous_var_nameX729);
int fls(int anonymous_var_nameX730);
int flsl(long anonymous_var_nameX731);
int flsll(long  long anonymous_var_nameX732);
char* index(const char* anonymous_var_nameX733, int anonymous_var_nameX734);
char* rindex(const char* anonymous_var_nameX735, int anonymous_var_nameX736);
int strcasecmp(const char* anonymous_var_nameX737, const char* anonymous_var_nameX738);
int strncasecmp(const char* anonymous_var_nameX739, const char* anonymous_var_nameX740, unsigned int anonymous_var_nameX741);
int strcasecmp_l(const char* anonymous_var_nameX742, const char* anonymous_var_nameX743, struct __locale_t* anonymous_var_nameX744);
int strncasecmp_l(const char* anonymous_var_nameX745, const char* anonymous_var_nameX746, unsigned int anonymous_var_nameX747, struct __locale_t* anonymous_var_nameX748);
void* memchr(const void* anonymous_var_nameX749, int anonymous_var_nameX750, unsigned int anonymous_var_nameX751);
int memcmp(const void* anonymous_var_nameX752, const void* anonymous_var_nameX753, unsigned int anonymous_var_nameX754);
void* memcpy(void* anonymous_var_nameX755, const void* anonymous_var_nameX756, unsigned int anonymous_var_nameX757);
void* memmove(void* anonymous_var_nameX758, const void* anonymous_var_nameX759, unsigned int anonymous_var_nameX760);
void* memset(void* anonymous_var_nameX761, int anonymous_var_nameX762, unsigned int anonymous_var_nameX763);
char* strcat(char* anonymous_var_nameX764, const char* anonymous_var_nameX765);
char* strchr(const char* anonymous_var_nameX766, int anonymous_var_nameX767);
int strcmp(const char* anonymous_var_nameX768, const char* anonymous_var_nameX769);
int strcoll(const char* anonymous_var_nameX770, const char* anonymous_var_nameX771);
char* strcpy(char* anonymous_var_nameX772, const char* anonymous_var_nameX773);
unsigned int strcspn(const char* anonymous_var_nameX774, const char* anonymous_var_nameX775);
char* strerror(int anonymous_var_nameX776);
unsigned int strlen(const char* anonymous_var_nameX777);
char* strncat(char* anonymous_var_nameX778, const char* anonymous_var_nameX779, unsigned int anonymous_var_nameX780);
int strncmp(const char* anonymous_var_nameX781, const char* anonymous_var_nameX782, unsigned int anonymous_var_nameX783);
char* strncpy(char* anonymous_var_nameX784, const char* anonymous_var_nameX785, unsigned int anonymous_var_nameX786);
char* strpbrk(const char* anonymous_var_nameX787, const char* anonymous_var_nameX788);
char* strrchr(const char* anonymous_var_nameX789, int anonymous_var_nameX790);
unsigned int strspn(const char* anonymous_var_nameX791, const char* anonymous_var_nameX792);
char* strstr(const char* anonymous_var_nameX793, const char* anonymous_var_nameX794);
char* strtok(char* anonymous_var_nameX795, const char* anonymous_var_nameX796);
unsigned int strxfrm(char* anonymous_var_nameX797, const char* anonymous_var_nameX798, unsigned int anonymous_var_nameX799);
int strcoll_l(const char* anonymous_var_nameX800, const char* anonymous_var_nameX801, struct __locale_t* anonymous_var_nameX802);
char* strerror_l(int anonymous_var_nameX803, struct __locale_t* anonymous_var_nameX804);
unsigned int strxfrm_l(char* anonymous_var_nameX805, const char* anonymous_var_nameX806, unsigned int anonymous_var_nameX807, struct __locale_t* anonymous_var_nameX808);
char* strtok_r(char* anonymous_var_nameX809, const char* anonymous_var_nameX810, char** anonymous_var_nameX811);
int timingsafe_bcmp(const void* anonymous_var_nameX812, const void* anonymous_var_nameX813, unsigned int anonymous_var_nameX814);
int timingsafe_memcmp(const void* anonymous_var_nameX815, const void* anonymous_var_nameX816, unsigned int anonymous_var_nameX817);
void* memccpy(void* anonymous_var_nameX818, const void* anonymous_var_nameX819, int anonymous_var_nameX820, unsigned int anonymous_var_nameX821);
void* mempcpy(void* anonymous_var_nameX822, const void* anonymous_var_nameX823, unsigned int anonymous_var_nameX824);
void* memmem(const void* anonymous_var_nameX825, unsigned int anonymous_var_nameX826, const void* anonymous_var_nameX827, unsigned int anonymous_var_nameX828);
void* memrchr(const void* anonymous_var_nameX829, int anonymous_var_nameX830, unsigned int anonymous_var_nameX831);
void* rawmemchr(const void* anonymous_var_nameX832, int anonymous_var_nameX833);
char* stpcpy(char* anonymous_var_nameX834, const char* anonymous_var_nameX835);
char* stpncpy(char* anonymous_var_nameX836, const char* anonymous_var_nameX837, unsigned int anonymous_var_nameX838);
char* strcasestr(const char* anonymous_var_nameX839, const char* anonymous_var_nameX840);
char* strchrnul(const char* anonymous_var_nameX841, int anonymous_var_nameX842);
char* strdup(const char* anonymous_var_nameX843);
char* _strdup_r(struct _reent* anonymous_var_nameX844, const char* anonymous_var_nameX845);
char* strndup(const char* anonymous_var_nameX846, unsigned int anonymous_var_nameX847);
char* _strndup_r(struct _reent* anonymous_var_nameX848, const char* anonymous_var_nameX849, unsigned int anonymous_var_nameX850);
char* strerror_r(int anonymous_var_nameX851, char* anonymous_var_nameX852, unsigned int anonymous_var_nameX853);
char* _strerror_r(struct _reent* anonymous_var_nameX854, int anonymous_var_nameX855, int anonymous_var_nameX856, int* anonymous_var_nameX857);
unsigned int strlcat(char* anonymous_var_nameX858, const char* anonymous_var_nameX859, unsigned int anonymous_var_nameX860);
unsigned int strlcpy(char* anonymous_var_nameX861, const char* anonymous_var_nameX862, unsigned int anonymous_var_nameX863);
unsigned int strnlen(const char* anonymous_var_nameX864, unsigned int anonymous_var_nameX865);
char* strsep(char** anonymous_var_nameX866, const char* anonymous_var_nameX867);
char* strnstr(const char* anonymous_var_nameX868, const char* anonymous_var_nameX869, unsigned int anonymous_var_nameX870);
char* strlwr(char* anonymous_var_nameX871);
char* strupr(char* anonymous_var_nameX872);
char* strsignal(int __signo);
int strverscmp(const char* anonymous_var_nameX873, const char* anonymous_var_nameX874);
char* __gnu_basename(const char* anonymous_var_nameX875);
void stdio_uart_init();
int getchar_timeout_us(uint32_t timeout_us);
void putchar(char c);
void init_task(void (*fun)());
static struct list$1sTask$ph* list$1sTask$ph_add(struct list$1sTask$ph* self, struct sTask* item);
static void sTask_finalize(struct sTask* self);
void save_context(struct sTask* task);
void restore_context(struct sTask* task);
_Bool timer_callback(struct repeating_timer* t);
static struct sTask* list$1sTask$ph$p_operator_load_element(struct list$1sTask$ph* self, int position);
static struct sTask* list$1sTask$ph_operator_load_element(struct list$1sTask$ph* self, int position);
static int list$1sTask$ph_length(struct list$1sTask$ph* self);
void task1();
void task2();
int main();
static struct list$1sTask$ph* list$1sTask$ph_initialize(struct list$1sTask$ph* self);
static void list$1sTask$ph$p_finalize(struct list$1sTask$ph* self);
static void list_item$1sTask$ph$p_finalize(struct list_item$1sTask$ph* self);
static void list$1sTask$ph_finalize(struct list$1sTask$ph* self);
static void repeating_timer_finalize(struct repeating_timer* self);
void come_push_stackframe(char* sname, int sline, int id);
void come_pop_stackframe();
void come_save_stackframe(char* sname, int sline);
void stackframe();
char* come_get_stackframe();
void xassert(char* msg, _Bool test);
_Bool die(char* msg);
void come_heap_init(int come_malloc, int come_debug, int come_gc);
void come_heap_final();
void* alloc_from_pages(unsigned int size);
void come_free_mem_of_heap_pool(void* mem);
void* come_alloc_mem_from_heap_pool(unsigned int size, char* sname, int sline, char* class_name);
void come_print_heap_info(void* mem);
char* come_dynamic_typeof(void* mem);
void* come_calloc(unsigned int count, unsigned int size, char* sname, int sline, char* class_name);
void come_free(void* mem);
void* come_memdup(void* block, char* sname, int sline, char* class_name);
void* come_increment_ref_count(void* mem);
void* come_print_ref_count(void* mem);
int come_get_ref_count(void* mem);
void* come_decrement_ref_count(void* mem, void* protocol_fun, void* protocol_obj, _Bool no_decrement, _Bool no_free, void* result_obj);
void come_call_finalizer(void* fun, void* mem, void* protocol_fun, void* protocol_obj, int call_finalizer_only, int no_decrement, int no_free, void* result_obj);
char* __builtin_string(char* str);
void come_push_stackframe_v2(char* sname, int sline, int id);
void come_pop_stackframe_v2();
void come_save_stackframe_v2(char* sname, int sline);
void stackframe_v2();
char* come_get_stackframe_v2();
void* come_calloc_v2(unsigned int count, unsigned int size, char* sname, int sline, char* class_name);
void come_free_v2(void* mem);
struct buffer* buffer_initialize(struct buffer* self);
struct buffer* buffer_initialize_with_value(struct buffer* self, char* mem, unsigned int size);
void buffer_finalize(struct buffer* self);
struct buffer* buffer_clone(struct buffer* self);
_Bool buffer_equals(struct buffer* left, struct buffer* right);
int buffer_length(struct buffer* self);
void buffer_reset(struct buffer* self);
void buffer_trim(struct buffer* self, int len);
struct buffer* buffer_append(struct buffer* self, char* mem, unsigned int size);
struct buffer* buffer_append_char(struct buffer* self, char c);
struct buffer* buffer_append_str(struct buffer* self, char* mem);
struct buffer* buffer_append_format(struct buffer* self, char* msg, ...);
struct buffer* buffer_append_nullterminated_str(struct buffer* self, char* mem);
struct buffer* buffer_append_int(struct buffer* self, int value);
struct buffer* buffer_append_long(struct buffer* self, long value);
struct buffer* buffer_append_short(struct buffer* self, short value);
struct buffer* buffer_alignment(struct buffer* self);
int buffer_compare(struct buffer* left, struct buffer* right);
struct buffer* charp_to_buffer(char* self);
char* buffer_to_string(struct buffer* self);
unsigned char* buffer_head_pointer(struct buffer* self);
struct buffer* charpa_to_buffer(char* self, unsigned int len);
struct buffer* charppa_to_buffer(char** self, unsigned int len);
struct buffer* shortpa_to_buffer(short* self, unsigned int len);
struct buffer* intpa_to_buffer(int* self, unsigned int len);
struct buffer* longpa_to_buffer(long* self, unsigned int len);
struct buffer* floatpa_to_buffer(float* self, unsigned int len);
struct buffer* doublepa_to_buffer(double* self, unsigned int len);
char* buffer_printable(struct buffer* self);
static struct list$1char$* list$1char$_initialize_with_values(struct list$1char$* self, int num_value, char* values);
static struct list$1char$* list$1char$_push_back(struct list$1char$* self, char item);
static void list$1char$$p_finalize(struct list$1char$* self);
static void list_item$1char$$p_finalize(struct list_item$1char$* self);
struct list$1char$* charpa_to_list(char* self, unsigned int len);
static struct list$1char$p* list$1char$p_initialize_with_values(struct list$1char$p* self, int num_value, char** values);
static struct list$1char$p* list$1char$p_push_back(struct list$1char$p* self, char* item);
static void list$1char$p$p_finalize(struct list$1char$p* self);
static void list_item$1char$p$p_finalize(struct list_item$1char$p* self);
struct list$1char$p* charppa_to_list(char** self, unsigned int len);
static struct list$1short$* list$1short$_initialize_with_values(struct list$1short$* self, int num_value, short* values);
static struct list$1short$* list$1short$_push_back(struct list$1short$* self, short item);
static void list$1short$$p_finalize(struct list$1short$* self);
static void list_item$1short$$p_finalize(struct list_item$1short$* self);
struct list$1short$* shortpa_to_list(short* self, unsigned int len);
static struct list$1int$* list$1int$_initialize_with_values(struct list$1int$* self, int num_value, int* values);
static struct list$1int$* list$1int$_push_back(struct list$1int$* self, int item);
static void list$1int$$p_finalize(struct list$1int$* self);
static void list_item$1int$$p_finalize(struct list_item$1int$* self);
struct list$1int$* intpa_to_list(int* self, unsigned int len);
static struct list$1long$* list$1long$_initialize_with_values(struct list$1long$* self, int num_value, long* values);
static struct list$1long$* list$1long$_push_back(struct list$1long$* self, long item);
static void list$1long$$p_finalize(struct list$1long$* self);
static void list_item$1long$$p_finalize(struct list_item$1long$* self);
struct list$1long$* longpa_to_list(long* self, unsigned int len);
static struct list$1float$* list$1float$_initialize_with_values(struct list$1float$* self, int num_value, float* values);
static struct list$1float$* list$1float$_push_back(struct list$1float$* self, float item);
static void list$1float$$p_finalize(struct list$1float$* self);
static void list_item$1float$$p_finalize(struct list_item$1float$* self);
struct list$1float$* floatpa_to_list(float* self, unsigned int len);
static struct list$1double$* list$1double$_initialize_with_values(struct list$1double$* self, int num_value, double* values);
static struct list$1double$* list$1double$_push_back(struct list$1double$* self, double item);
static void list$1double$$p_finalize(struct list$1double$* self);
static void list_item$1double$$p_finalize(struct list_item$1double$* self);
struct list$1double$* doublepa_to_list(double* self, unsigned int len);
_Bool bool_equals(_Bool self, _Bool right);
_Bool _Bool_equals(_Bool self, _Bool right);
_Bool char_equals(char self, char right);
_Bool short_equals(short self, short right);
_Bool int_equals(int self, int right);
_Bool long_equals(long self, long right);
_Bool size_t_equals(unsigned int self, unsigned int right);
_Bool float_equals(float self, float right);
_Bool double_equals(double self, double right);
_Bool bool_operator_equals(_Bool self, _Bool right);
_Bool _Bool_operator_equals(_Bool self, _Bool right);
_Bool char_operator_equals(char self, char right);
_Bool short_operator_equals(short self, short right);
_Bool int_operator_equals(int self, int right);
_Bool long_operator_equals(long self, long right);
_Bool bool_operator_not_equals(_Bool self, _Bool right);
_Bool _Bool_operator_not_equals(_Bool self, _Bool right);
_Bool char_operator_not_equals(char self, char right);
_Bool short_operator_not_equals(short self, short right);
_Bool int_operator_not_equals(int self, int right);
_Bool long_operator_not_equals(long self, long right);
_Bool charp_equals(char* self, char* right);
_Bool string_equals(char* self, char* right);
_Bool voidp_equals(void* self, void* right);
_Bool boolp_equals(_Bool* self, _Bool* right);
_Bool string_operator_equals(char* self, char* right);
_Bool charp_operator_equals(char* self, char* right);
_Bool voidp_operator_equals(char* self, char* right);
_Bool voidp_operator_not_equals(char* self, char* right);
_Bool string_operator_not_equals(char* self, char* right);
_Bool charp_operator_not_equals(char* self, char* right);
char* charp_operator_add(char* self, char* right);
char* string_operator_add(char* self, char* right);
char* charp_operator_mult(char* self, int right);
char* string_operator_mult(char* self, int right);
unsigned int charpa_length(char* self, unsigned int len);
_Bool charppa_contained(char** self, unsigned int len, char* str);
unsigned int shortpa_length(short* self, unsigned int len);
unsigned int intpa_length(int* self, unsigned int len);
unsigned int longpa_length(long* self, unsigned int len);
unsigned int floatpa_length(float* self, unsigned int len);
unsigned int doublepa_length(double* self, unsigned int len);
unsigned int bool_get_hash_key(_Bool value);
unsigned int _Bool_get_hash_key(_Bool value);
unsigned int char_get_hash_key(char value);
unsigned int short_get_hash_key(short int value);
unsigned int int_get_hash_key(int value);
unsigned int long_get_hash_key(long value);
unsigned int size_t_get_hash_key(unsigned int value);
unsigned int float_get_hash_key(float value);
unsigned int double_get_hash_key(double value);
unsigned int charp_get_hash_key(char* value);
unsigned int string_get_hash_key(char* value);
unsigned int voidp_get_hash_key(void* value);
_Bool bool_clone(_Bool self);
_Bool _Bool_clone(_Bool self);
char char_clone(char self);
short int short_clone(short self);
int int_clone(int self);
long  int long_clone(long self);
unsigned int size_t_clone(unsigned int self);
double double_clone(double self);
float float_clone(float self);
_Bool xisalpha(char c);
_Bool xisblank(char c);
_Bool xisdigit(char c);
_Bool xisspace(char c);
_Bool xisalnum(char c);
_Bool xisascii(char c);
_Bool xispunct(char c);
int string_length(char* str);
int charp_length(char* str);
char* charp_reverse(char* str);
char* string_operator_load_range_element(char* str, int head, int tail);
char* charp_operator_load_range_element(char* str, int head, int tail);
char* charp_substring(char* str, int head, int tail);
char* xsprintf(char* msg, ...);
char* charp_delete(char* str, int head, int tail);
static struct list$1char$ph* list$1char$ph_initialize(struct list$1char$ph* self);
static void list$1char$ph$p_finalize(struct list$1char$ph* self);
static void list_item$1char$ph$p_finalize(struct list_item$1char$ph* self);
static struct list$1char$ph* list$1char$ph_push_back(struct list$1char$ph* self, char* item);
struct list$1char$ph* charp_split_char(char* self, char c);
char* charp_xsprintf(char* self, char* msg, ...);
char* int_xsprintf(int self, char* msg, ...);
char* charp_printable(char* str);
char* charp_sub_plain(char* self, char* str, char* replace);
char* xbasename(char* path);
char* xnoextname(char* path);
char* xextname(char* path);
char* bool_to_string(_Bool self);
char* _Bool_to_string(_Bool self);
char* char_to_string(char self);
char* short_to_string(short self);
char* int_to_string(int self);
char* long_to_string(long self);
char* size_t_to_string(unsigned int self);
char* float_to_string(float self);
char* double_to_string(double self);
char* string_to_string(char* self);
char* charp_to_string(char* self);
int bool_compare(_Bool left, _Bool right);
int _Bool_compare(_Bool left, _Bool right);
int char_compare(char left, char right);
int short_compare(short left, short right);
int int_compare(int left, int right);
int long_compare(long left, long right);
int size_t_compare(unsigned int left, unsigned int right);
int float_compare(float left, float right);
int double_compare(double left, double right);
int string_compare(char* left, char* right);
int charp_compare(char* left, char* right);
char* charp_puts(char* self);
char* charp_print(char* self);
char* charp_printf(char* self, ...);
int int_printf(int self, char* msg);
void int_times(int self, void* parent, void (*block)(void*,int));
static void match_context_finalize(struct anonymous_typeX18* self);
int re_matchp(struct re_program* pattern, const char* text, int* matchlength, struct re_capture* captures, int max_captures);
int re_match(const char* pattern, const char* text, int* matchlength);
static void regex_program_t_finalize(struct re_program* self);
static void compiler_state_finalize(struct anonymous_typeX17* self);
struct re_program* re_compile(const char* pattern);
void re_print(struct re_program* pattern);
void clear_captures(struct anonymous_typeX18* ctx);
void snapshot_captures(const struct anonymous_typeX18* ctx, struct re_capture* buffer_);
void restore_captures(struct anonymous_typeX18* ctx, const struct re_capture* buffer_);
struct regex_t* new_token(struct anonymous_typeX17* st);
int append_token(struct regex_t** head, struct regex_t** tail, struct regex_t* token);
struct regex_t* compile_sequence(struct anonymous_typeX17* st, const char* pattern, int* pos, int in_group);
const char* matchpattern(struct regex_t* pattern, const char* text, struct anonymous_typeX18* ctx);
const char* matchstar(struct regex_t* token, struct regex_t* rest, const char* text, struct anonymous_typeX18* ctx);
const char* matchplus(struct regex_t* token, struct regex_t* rest, const char* text, struct anonymous_typeX18* ctx);
const char* matchquestion(struct regex_t* token, struct regex_t* rest, const char* text, struct anonymous_typeX18* ctx);
const char* matchtoken(struct regex_t* token, const char* text, struct anonymous_typeX18* ctx);
int matchdigit(char c);
int matchalpha(char c);
int matchwhitespace(char c);
int matchalphanum(char c);
int matchrange(char c, const char* str);
int matchdot(char c);
int ismetachar(char c);
int matchmetachar(char c, const char* str);
int matchcharclass(char c, const char* str);
void re_print_internal(struct regex_t* pattern, int depth);
int re_get_group_count(struct re_program* pattern);
char* string_lower_case(char* str);
char* string_upper_case(char* str);
int charp_index_regex(char* self, char* reg, int default_value);
int charp_rindex(char* str, char* search_str, int default_value);
int charp_rindex_regex(char* self, char* reg, int default_value);
char* charp_strip(char* self);
int charp_index(char* str, char* search_str, int default_value);
char* string_chomp(char* str);
char* charp_replace(char* self, int index, char c);
char* charp_multiply(char* str, int n);
struct list$1char$ph* charp_split_str(char* self, char* str);
int string_rindex(char* str, char* search_str, int default_value);
int string_rindex_regex(char* self, char* reg, int default_value);
char* string_strip(char* self);
int string_index(char* str, char* search_str, int default_value);
int string_index_regex(char* self, char* reg, int default_value);
char* string_replace(char* self, int index, char c);
char* string_multiply(char* str, int n);
_Bool charp_match(char* self, char* reg);
static struct list$1char$ph* list$1char$ph_add(struct list$1char$ph* self, char* item);
struct list$1char$ph* charp_scan(char* self, char* reg);
struct list$1char$ph* charp_split(char* self, char* reg);
char* string_sub(char* self, char* reg, char* replace);
struct list$1char$ph* string_split_str(char* self, char* str);
struct list$1char$ph* string_scan(char* self, char* reg);
struct list$1char$ph* string_split(char* self, char* reg);
_Bool string_match(char* self, char* reg);
char* charp_sub(char* self, char* reg, char* replace);
char* charp_sub_block(char* self, char* reg, void* parent, char* (*block)(void*,char*,struct list$1char$ph*));
struct list$1char$ph* charp_scan_block(char* self, char* reg, void* parent, char* (*block)(void*,char*,struct list$1char$ph*));
char* string_sub_block(char* self, char* reg, void* parent, char* (*block)(void*,char*,struct list$1char$ph*));
// uniq global variable
struct sMemHeader* gAllocMem;

int gComeDebugLib=0;

int gNumAlloc=0;

int gNumFree=0;

// inline function
static inline int __sputc_r(struct _reent* _ptr, int _c, struct __sFILE* _p){
}
static inline int _getchar_unlocked(){
}
static inline int _putchar_unlocked(int _c){
}
static inline void stdio_usb_init(){
}
static inline void stdio_init_all(){
}
static inline void stdio_filter_driver(struct stdio_driver* driver){
}
static inline void stdio_set_translate_crlf(struct stdio_driver* driver, _Bool enabled){
}
static inline _Bool stdio_usb_connected(){
}

// body function
void putchar(char c){
    char buf[2];
    memset(&buf, 0, sizeof(char)    *(2)    );
    buf[0]=c;
    buf[1]=0;
    puts(buf);
}

void init_task(void (*fun)()){
uint32_t* stack;
uint32_t* stack_end;
int i;
void* __right_value0 = (void*)0;
struct sTask* task;
memset(&i, 0, sizeof(int));
    stack=(uint32_t*)calloc(1,sizeof(uint32_t)*1024);
    stack_end=(uint32_t*)(&stack[1024-1]);
    *(--stack_end)=0x01000000;
    *(--stack_end)=(uint32_t)fun;
    *(--stack_end)=0xFFFFFFFD;
    for(    i=0    ;    i<5    ;    i++    ){
        *(--stack_end)=0;
    }
    task=(struct sTask*)come_increment_ref_count((struct sTask*)come_calloc_v2(1, sizeof(struct sTask)*(1), "main.c", 47, "struct sTask*"));
    task->sp=(uint32_t)stack_end;
    list$1sTask$ph_add(gTasks,(struct sTask*)come_increment_ref_count(task));
    come_call_finalizer(sTask_finalize, task, (void*)0, (void*)0, 0, 0, 0, (void*)0);
}

static struct list$1sTask$ph* list$1sTask$ph_add(struct list$1sTask$ph* self, struct sTask* item){
void* __right_value0 = (void*)0;
struct list_item$1sTask$ph* litem;
struct sTask* __dec_obj1;
struct list_item$1sTask$ph* litem_0;
struct sTask* __dec_obj2;
struct list_item$1sTask$ph* litem_1;
struct sTask* __dec_obj3;
struct list$1sTask$ph* __result_obj__1;
    if(    self->len==0    ) {
        litem=(struct list_item$1sTask$ph*)come_increment_ref_count(((struct list_item$1sTask$ph*)(__right_value0=(struct list_item$1sTask$ph*)come_calloc_v2(1, sizeof(struct list_item$1sTask$ph)*(1), "/usr/local/include/comelang.h", 6161, "struct list_item$1sTask$ph*"))));
        litem->prev=((void*)0);
        litem->next=((void*)0);
        __dec_obj1=litem->item,
        litem->item=(struct sTask*)come_increment_ref_count(item);
        come_call_finalizer(sTask_finalize, __dec_obj1,(void*)0, (void*)0, 0, 0, 0, (void*)0);
        self->tail=litem;
        self->head=litem;
    }
    else if(    self->len==1    ) {
        __right_value0 = (void*)0;
        litem_0=(struct list_item$1sTask$ph*)come_increment_ref_count(((struct list_item$1sTask$ph*)(__right_value0=(struct list_item$1sTask$ph*)come_calloc_v2(1, sizeof(struct list_item$1sTask$ph)*(1), "/usr/local/include/comelang.h", 6171, "struct list_item$1sTask$ph*"))));
        litem_0->prev=self->head;
        litem_0->next=((void*)0);
        __dec_obj2=litem_0->item,
        litem_0->item=(struct sTask*)come_increment_ref_count(item);
        come_call_finalizer(sTask_finalize, __dec_obj2,(void*)0, (void*)0, 0, 0, 0, (void*)0);
        self->tail=litem_0;
        self->head->next=litem_0;
    }
    else {
        __right_value0 = (void*)0;
        litem_1=(struct list_item$1sTask$ph*)come_increment_ref_count(((struct list_item$1sTask$ph*)(__right_value0=(struct list_item$1sTask$ph*)come_calloc_v2(1, sizeof(struct list_item$1sTask$ph)*(1), "/usr/local/include/comelang.h", 6181, "struct list_item$1sTask$ph*"))));
        litem_1->prev=self->tail;
        litem_1->next=((void*)0);
        __dec_obj3=litem_1->item,
        litem_1->item=(struct sTask*)come_increment_ref_count(item);
        come_call_finalizer(sTask_finalize, __dec_obj3,(void*)0, (void*)0, 0, 0, 0, (void*)0);
        self->tail->next=litem_1;
        self->tail=litem_1;
    }
    self->len++;
    __result_obj__1 = self;
    come_call_finalizer(sTask_finalize, item, (void*)0, (void*)0, 0, 0, 0, (void*)0);
    return __result_obj__1;
}

static void sTask_finalize(struct sTask* self){
}

void save_context(struct sTask* task){
    __asm volatile("ldr r0, =R4; \n"
        "str r4, [r0];\n"
        :
        :
        : "r0", "r4"
    );
    task->r4=R4;
    __asm volatile("ldr r0, =R5; \n"
        "str r5, [r0];\n"
        :
        :
        : "r0", "r5"
    );
    task->r5=R5;
    __asm volatile("ldr r0, =R6; \n"
        "str r6, [r0];\n"
        :
        :
        : "r0", "r6"
    );
    task->r6=R6;
    __asm volatile("ldr r0, =R7; \n"
        "str r7, [r0];\n"
        :
        :
        : "r0", "r7"
    );
    task->r7=R7;
    __asm volatile("ldr r0, =R8; \n"
        "mov r3, r8;\n"
        "str r3, [r0];\n"
        :
        :
        : "r0", "r3", "r8"
    );
    task->r8=R8;
    __asm volatile("ldr r0, =R9; \n"
        "mov r3, r9;\n"
        "str r3, [r0];\n"
        :
        :
        : "r0", "r3", "r9"
    );
    task->r9=R9;
    __asm volatile("ldr r0, =R10; \n"
        "mov r3, r10;\n"
        "str r3, [r0];\n"
        :
        :
        : "r0", "r3", "r10"
    );
    task->r10=R10;
    __asm volatile("ldr r0, =R11; \n"
        "mov r3, r11;\n"
        "str r3, [r0];\n"
        :
        :
        : "r0", "r3", "r11"
    );
    task->r11=R11;
    __asm volatile("mrs r1, psp\n"
        "ldr r0, =SP; \n"
        "str r1, [r0]; \n"
        :
        :
        : "r0", "r1"
    );
    task->sp=SP;
}

void restore_context(struct sTask* task){
    SP=task->sp;
    PC=*((uint32_t*)SP+6);
    __asm volatile("ldr r0, =SP; \n"
        "ldr r3, [r0]; \n"
        "msr psp, r3; \n"
        :
        :
        : "r0", "r3"
    );
    R11=task->r11;
    __asm volatile("ldr r0, =R11; \n"
        "ldr r4, [r0];\n"
        "mov r11, r4;\n"
        :
        :
        : "r0", "r4", "r11"
    );
    R10=task->r10;
    __asm volatile("ldr r0, =R10; \n"
        "ldr r4, [r0];\n"
        "mov r10, r4;\n"
        :
        :
        : "r0", "r4", "r10"
    );
    R9=task->r9;
    __asm volatile("ldr r0, =R9; \n"
        "ldr r4, [r0];\n"
        "mov r9, r4;\n"
        :
        :
        : "r0", "r4", "r9"
    );
    R8=task->r8;
    __asm volatile("ldr r0, =R8; \n"
        "ldr r4, [r0];\n"
        "mov r8, r4;\n"
        :
        :
        : "r0", "r4", "r8"
    );
    R7=task->r7;
    __asm volatile("ldr r0, =R7; \n"
        "ldr r7, [r0];\n"
        :
        :
        : "r0", "r7"
    );
    R6=task->r6;
    __asm volatile("ldr r0, =R6; \n"
        "ldr r6, [r0];\n"
        :
        :
        : "r0", "r6"
    );
    R5=task->r5;
    __asm volatile("ldr r0, =R5; \n"
        "ldr r5, [r0];\n"
        :
        :
        : "r0", "r5"
    );
    R4=task->r4;
    __asm volatile("ldr r0, =R4; \n"
        "ldr r4, [r0];\n"
        :
        :
        : "r0", "r4"
    );
}

_Bool timer_callback(struct repeating_timer* t){
void* __right_value0 = (void*)0;
    save_context(((struct sTask*)(__right_value0=list$1sTask$ph_operator_load_element(gTasks,gCurrentTask))));
    come_call_finalizer(sTask_finalize, __right_value0, (void*)0, (void*)0, 0, 1, 0, (void*)0);
    gCurrentTask=(gCurrentTask+1)%list$1sTask$ph_length(gTasks);
    __right_value0 = (void*)0;
    restore_context(((struct sTask*)(__right_value0=list$1sTask$ph_operator_load_element(gTasks,gCurrentTask))));
    come_call_finalizer(sTask_finalize, __right_value0, (void*)0, (void*)0, 0, 1, 0, (void*)0);
    return (_Bool)1;
}

static struct sTask* list$1sTask$ph$p_operator_load_element(struct list$1sTask$ph* self, int position){
struct list_item$1sTask$ph* it;
int i;
struct sTask* __result_obj__2;
struct sTask* default_value;
struct sTask* __result_obj__3;
default_value = (void*)0;
    if(    position<0    ) {
        position+=self->len;
    }
    it=self->head;
    i=0;
    while(    it!=((void*)0)    ) {
        if(        position==i        ) {
            __result_obj__2 = (struct sTask*)come_increment_ref_count(it->item);
            come_call_finalizer(sTask_finalize, __result_obj__2, (void*)0, (void*)0, 0, 0, 1, (void*)0);
            return __result_obj__2;
        }
        it=it->next;
        i++;
    }
    memset(&default_value,0,sizeof(struct sTask*));
    __result_obj__3 = (struct sTask*)come_increment_ref_count(default_value);
    come_call_finalizer(sTask_finalize, default_value, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    come_call_finalizer(sTask_finalize, __result_obj__3, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__3;
}

static struct sTask* list$1sTask$ph_operator_load_element(struct list$1sTask$ph* self, int position){
struct list_item$1sTask$ph* it;
int i;
struct sTask* __result_obj__4;
struct sTask* default_value;
struct sTask* __result_obj__5;
default_value = (void*)0;
    if(    position<0    ) {
        position+=self->len;
    }
    it=self->head;
    i=0;
    while(    it!=((void*)0)    ) {
        if(        position==i        ) {
            __result_obj__4 = (struct sTask*)come_increment_ref_count(it->item);
            come_call_finalizer(sTask_finalize, __result_obj__4, (void*)0, (void*)0, 0, 0, 1, (void*)0);
            return __result_obj__4;
        }
        it=it->next;
        i++;
    }
    memset(&default_value,0,sizeof(struct sTask*));
    __result_obj__5 = (struct sTask*)come_increment_ref_count(default_value);
    come_call_finalizer(sTask_finalize, default_value, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    come_call_finalizer(sTask_finalize, __result_obj__5, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__5;
}

static int list$1sTask$ph_length(struct list$1sTask$ph* self){
    if(    self==((void*)0)    ) {
        return 0;
    }
    return self->len;
}

void task1(){
    while(    1    ) {
        puts("TASK1");
        sleep_ms(1000);
        puts("TASK1-2");
        sleep_ms(1000);
    }
}

void task2(){
    while(    1    ) {
        puts("TASK2");
        sleep_ms(1000);
        puts("TASK2-2");
        sleep_ms(1000);
    }
}

int main(){
void* __right_value0 = (void*)0;
void* __right_value1 = (void*)0;
struct list$1sTask$ph* __dec_obj4;
struct repeating_timer timer;
int __result_obj__7;
memset(&timer, 0, sizeof(struct repeating_timer));
    come_heap_init(0, 0, 0);
    stdio_init_all();
    sleep_ms(5000);
    __dec_obj4=gTasks,
    gTasks=(struct list$1sTask$ph*)come_increment_ref_count(list$1sTask$ph_initialize((struct list$1sTask$ph*)come_increment_ref_count((struct list$1sTask$ph*)come_calloc_v2(1, sizeof(struct list$1sTask$ph)*(1), "main.c", 256, "struct list$1sTask$ph*"))));
    come_call_finalizer(list$1sTask$ph_finalize, __dec_obj4,(void*)0, (void*)0, 0, 0, 0, (void*)0);
    init_task(task1);
    init_task(task2);
    __right_value0 = (void*)0;
    SP=((struct sTask*)(__right_value0=list$1sTask$ph_operator_load_element(gTasks,gCurrentTask)))->sp;
    come_call_finalizer(sTask_finalize, __right_value0, (void*)0, (void*)0, 0, 1, 0, (void*)0);
    add_repeating_timer_ms(1000,timer_callback,((void*)0),&timer);
    __asm volatile("ldr r0, =SP; \n"
        "ldr r4, [r0]; \n"
        "msr psp, r4\n"
        "mov r0, #0x02\n"
        "msr CONTROL, r0\n"
        "isb\n"
        :
        :
        : "r0","r4" // 使用するレジスタ
    );
    task1();
    while(    (_Bool)1    ) {
    }
    __result_obj__7 = 0;
    come_call_finalizer(repeating_timer_finalize, (&timer), (void*)0, (void*)0, 1, 0, 0, (void*)0);
    come_call_finalizer(list$1sTask$ph$p_finalize, gTasks, (void*)0, (void*)0, 0, 0, 0, (void*)0);
    come_heap_final();
    return __result_obj__7;
}

static struct list$1sTask$ph* list$1sTask$ph_initialize(struct list$1sTask$ph* self){
struct list$1sTask$ph* __result_obj__6;
    self->head=((void*)0);
    self->tail=((void*)0);
    self->len=0;
    __result_obj__6 = (struct list$1sTask$ph*)come_increment_ref_count(self);
    come_call_finalizer(list$1sTask$ph$p_finalize, self, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    come_call_finalizer(list$1sTask$ph$p_finalize, __result_obj__6, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__6;
}

static void list$1sTask$ph$p_finalize(struct list$1sTask$ph* self){
struct list_item$1sTask$ph* it;
struct list_item$1sTask$ph* prev_it;
    it=self->head;
    while(    it!=((void*)0)    ) {
        prev_it=it;
        it=it->next;
        come_call_finalizer(list_item$1sTask$ph$p_finalize, prev_it, (void*)0, (void*)0, 0, 0, 0, (void*)0);
    }
}

static void list_item$1sTask$ph$p_finalize(struct list_item$1sTask$ph* self){
    if(    self!=((void*)0)&&self->item!=((void*)0)    ) {
        come_call_finalizer(sTask_finalize, self->item, (void*)0, (void*)0, 0, 0, 0, (void*)0);
    }
}

static void list$1sTask$ph_finalize(struct list$1sTask$ph* self){
struct list_item$1sTask$ph* it;
struct list_item$1sTask$ph* prev_it;
    it=self->head;
    while(    it!=((void*)0)    ) {
        prev_it=it;
        it=it->next;
        come_call_finalizer(list_item$1sTask$ph$p_finalize, prev_it, (void*)0, (void*)0, 0, 0, 0, (void*)0);
    }
}

static void repeating_timer_finalize(struct repeating_timer* self){
}

void come_push_stackframe(char* sname, int sline, int id){
}

void come_pop_stackframe(){
}

void come_save_stackframe(char* sname, int sline){
}

void stackframe(){
}

char* come_get_stackframe(){
void* __right_value0 = (void*)0;
char* __result_obj__8;
    __result_obj__8 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__8 = come_decrement_ref_count(__result_obj__8, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__8;
}

void xassert(char* msg, _Bool test){
    printf("%s...",msg);
    if(    !test    ) {
        puts("false");
        exit(2);
    }
    puts("ok");
}

_Bool die(char* msg){
    puts(msg);
    exit(4);
    return (_Bool)0;
}

void come_heap_init(int come_malloc, int come_debug, int come_gc){
}

void come_heap_final(){
}

void* alloc_from_pages(unsigned int size){
void* result;
void* __result_obj__9;
    result=((void*)0);
    size=(size+3&~0x3);
    result=calloc(1,size);
    __result_obj__9 = result;
    return __result_obj__9;
}

void come_free_mem_of_heap_pool(void* mem){
struct sMemHeaderTiny* it;
struct sMemHeaderTiny* prev_it;
struct sMemHeaderTiny* next_it;
unsigned int size;
    if(    mem    ) {
        if(        gComeDebugLib        ) {
        }
        else {
            it=(struct sMemHeaderTiny*)((char*)mem-sizeof(struct sMemHeaderTiny));
            if(            it->allocated!=177783            ) {
                return;
            }
            it->allocated=0;
            prev_it=it->prev;
            next_it=it->next;
            if(            gAllocMem==it            ) {
                gAllocMem=(struct sMemHeader*)next_it;
                if(                gAllocMem                ) {
                    gAllocMem->prev=((void*)0);
                }
            }
            else {
                if(                prev_it                ) {
                    prev_it->next=next_it;
                }
                if(                next_it                ) {
                    next_it->prev=prev_it;
                }
            }
            size=it->size;
            free(it);
            gNumFree++;
        }
    }
}

void* come_alloc_mem_from_heap_pool(unsigned int size, char* sname, int sline, char* class_name){
void* result;
struct sMemHeaderTiny* it;
void* __result_obj__10;
    if(    gComeDebugLib    ) {
    }
    else {
        result=alloc_from_pages(size+sizeof(struct sMemHeaderTiny));
        it=result;
        it->allocated=177783;
        it->class_name=class_name;
        it->sname=sname;
        it->sline=sline;
        it->size=size+sizeof(struct sMemHeaderTiny);
        it->free_next=((void*)0);
        it->next=(struct sMemHeaderTiny*)gAllocMem;
        it->prev=((void*)0);
        if(        gAllocMem        ) {
            ((struct sMemHeaderTiny*)gAllocMem)->prev=it;
        }
        gAllocMem=(struct sMemHeader*)it;
        gNumAlloc++;
        __result_obj__10 = (char*)result+sizeof(struct sMemHeaderTiny);
        return __result_obj__10;
    }
}

void come_print_heap_info(void* mem){
}

char* come_dynamic_typeof(void* mem){
struct sMemHeader* it;
char* __result_obj__11;
struct sMemHeaderTiny* it_2;
char* __result_obj__12;
    if(    gComeDebugLib    ) {
        it=(struct sMemHeader*)((char*)mem-sizeof(unsigned int)-sizeof(unsigned int)-sizeof(struct sMemHeader));
        if(        it->allocated!=177783        ) {
            printf("invalid heap object(%p)(1)\n",it);
            exit(2);
        }
        __result_obj__11 = it->class_name;
        return __result_obj__11;
    }
    else {
        it_2=(struct sMemHeaderTiny*)((char*)mem-sizeof(unsigned int)-sizeof(unsigned int)-sizeof(struct sMemHeaderTiny));
        if(        it_2->allocated!=177783        ) {
            printf("invalid heap object(%p)(2)\n",it_2);
            exit(2);
        }
        __result_obj__12 = it_2->class_name;
        return __result_obj__12;
    }
}

void* come_calloc(unsigned int count, unsigned int size, char* sname, int sline, char* class_name){
char* mem;
unsigned int* ref_count;
unsigned int* size2;
void* __result_obj__13;
    mem=come_alloc_mem_from_heap_pool(sizeof(unsigned int)+sizeof(unsigned int)+count*size,sname,sline,class_name);
    ref_count=(unsigned int*)mem;
    *ref_count=0;
    size2=(unsigned int*)(mem+sizeof(unsigned int));
    *size2=size*count+sizeof(unsigned int)+sizeof(unsigned int);
    __result_obj__13 = mem+sizeof(unsigned int)+sizeof(unsigned int);
    return __result_obj__13;
}

void come_free(void* mem){
unsigned int* ref_count;
    if(    mem==((void*)0)    ) {
        return;
    }
    ref_count=(unsigned int*)((char*)mem-sizeof(unsigned int)-sizeof(unsigned int));
    come_free_mem_of_heap_pool((char*)ref_count);
}

void* come_memdup(void* block, char* sname, int sline, char* class_name){
void* __result_obj__14;
char* mem;
unsigned int* size_p;
unsigned int size;
void* result;
void* __result_obj__15;
    if(    !block    ) {
        __result_obj__14 = ((void*)0);
        return __result_obj__14;
    }
    mem=(char*)block-sizeof(unsigned int)-sizeof(unsigned int);
    size_p=(unsigned int*)(mem+sizeof(unsigned int));
    size=*size_p-sizeof(unsigned int)-sizeof(unsigned int);
    result=come_calloc_v2(1,size,sname,sline,class_name);
    memcpy(result,block,size);
    __result_obj__15 = result;
    return __result_obj__15;
}

void* come_increment_ref_count(void* mem){
void* __result_obj__16;
unsigned int* ref_count;
void* __result_obj__17;
    if(    mem==((void*)0)    ) {
        __result_obj__16 = mem;
        return __result_obj__16;
    }
    ref_count=(unsigned int*)((char*)mem-sizeof(unsigned int)-sizeof(unsigned int));
    (*ref_count)++;
    __result_obj__17 = mem;
    return __result_obj__17;
}

void* come_print_ref_count(void* mem){
void* __result_obj__18;
unsigned int* ref_count;
void* __result_obj__19;
    if(    mem==((void*)0)    ) {
        __result_obj__18 = mem;
        return __result_obj__18;
    }
    ref_count=(unsigned int*)((char*)mem-sizeof(unsigned int)-sizeof(unsigned int));
    printf("ref_count %ld\n",*ref_count);
    __result_obj__19 = mem;
    return __result_obj__19;
}

int come_get_ref_count(void* mem){
unsigned int* ref_count;
    if(    mem==((void*)0)    ) {
        return 0;
    }
    ref_count=(unsigned int*)((char*)mem-sizeof(unsigned int)-sizeof(unsigned int));
    return *ref_count;
}

void* come_decrement_ref_count(void* mem, void* protocol_fun, void* protocol_obj, _Bool no_decrement, _Bool no_free, void* result_obj){
void* __result_obj__20;
void* __result_obj__21;
unsigned int* ref_count;
unsigned int count;
void (*finalizer)(void*);
void* __result_obj__22;
void* __result_obj__23;
    if(    result_obj    ) {
        if(        mem==result_obj        ) {
            __result_obj__20 = mem;
            return __result_obj__20;
        }
    }
    if(    mem==((void*)0)    ) {
        __result_obj__21 = ((void*)0);
        return __result_obj__21;
    }
    ref_count=(unsigned int*)((char*)mem-sizeof(unsigned int)-sizeof(unsigned int));
    if(    !no_decrement    ) {
        (*ref_count)--;
    }
    count=*ref_count;
    if(    !no_free&&count<=0    ) {
        if(        protocol_obj&&protocol_fun        ) {
            finalizer=protocol_fun;
            finalizer(protocol_obj);
            come_free_v2(protocol_obj);
        }
        come_free_v2(mem);
        __result_obj__22 = ((void*)0);
        return __result_obj__22;
    }
    __result_obj__23 = mem;
    return __result_obj__23;
}

void come_call_finalizer(void* fun, void* mem, void* protocol_fun, void* protocol_obj, int call_finalizer_only, int no_decrement, int no_free, void* result_obj){
void (*finalizer)(void*);
void (*finalizer_3)(void*);
void (*finalizer_4)(void*);
unsigned int* ref_count;
unsigned int count;
void (*finalizer_5)(void*);
void (*finalizer_6)(void*);
void (*finalizer_7)(void*);
    if(    result_obj    ) {
        if(        mem==result_obj        ) {
            return;
        }
    }
    if(    mem==((void*)0)    ) {
        return;
    }
    if(    call_finalizer_only    ) {
        if(        fun        ) {
            if(            protocol_obj&&protocol_fun            ) {
                finalizer=protocol_fun;
                finalizer(protocol_obj);
            }
            finalizer_3=fun;
            finalizer_3(mem);
        }
        else {
            if(            protocol_obj&&protocol_fun            ) {
                finalizer_4=protocol_fun;
                finalizer_4(protocol_obj);
            }
        }
    }
    else {
        ref_count=(unsigned int*)((char*)mem-sizeof(unsigned int)-sizeof(unsigned int));
        if(        !no_decrement        ) {
            (*ref_count)--;
        }
        count=*ref_count;
        if(        !no_free&&count<=0        ) {
            if(            mem            ) {
                if(                fun                ) {
                    if(                    protocol_obj&&protocol_fun                    ) {
                        finalizer_5=protocol_fun;
                        finalizer_5(protocol_obj);
                        come_free_v2(protocol_obj);
                    }
                    if(                    fun                    ) {
                        finalizer_6=fun;
                        finalizer_6(mem);
                    }
                }
                else {
                    if(                    protocol_obj&&protocol_fun                    ) {
                        finalizer_7=protocol_fun;
                        finalizer_7(protocol_obj);
                        come_free_v2(protocol_obj);
                    }
                }
                come_free_v2(mem);
            }
        }
    }
}

char* __builtin_string(char* str){
char* __result_obj__24;
int len;
void* __right_value0 = (void*)0;
char* result;
char* __result_obj__25;
    if(    str==((void*)0)    ) {
        __result_obj__24 = (void*)come_increment_ref_count(((void*)0));
        (__result_obj__24 = come_decrement_ref_count(__result_obj__24, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__24;
    }
    len=strlen(str)+1;
    result=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(len)), "/usr/local/include/comelang.h", 6045, "char*"));
    strncpy(result,str,len);
    __result_obj__25 = (char*)come_increment_ref_count(result);
    (result = come_decrement_ref_count(result, (void*)0, (void*)0, 0, 1, (void*)0));
    (__result_obj__25 = come_decrement_ref_count(__result_obj__25, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__25;
}

void come_push_stackframe_v2(char* sname, int sline, int id){
    come_push_stackframe(sname,sline,id);
}

void come_pop_stackframe_v2(){
    come_pop_stackframe();
}

void come_save_stackframe_v2(char* sname, int sline){
    come_save_stackframe(sname,sline);
}

void stackframe_v2(){
    stackframe();
}

char* come_get_stackframe_v2(){
void* __right_value0 = (void*)0;
char* __result_obj__26;
    __result_obj__26 = (char*)come_increment_ref_count(((char*)(__right_value0=come_get_stackframe())));
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__26 = come_decrement_ref_count(__result_obj__26, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__26;
}

void* come_calloc_v2(unsigned int count, unsigned int size, char* sname, int sline, char* class_name){
void* __result_obj__27;
    __result_obj__27 = come_calloc(count,size,sname,sline,class_name);
    return __result_obj__27;
}

void come_free_v2(void* mem){
    come_free(mem);
}

struct buffer* buffer_initialize(struct buffer* self){
void* __right_value0 = (void*)0;
char* __dec_obj5;
struct buffer* __result_obj__28;
    self->size=128;
    __dec_obj5=self->buf,
    self->buf=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(self->size)), "/usr/local/include/comelang.h", 8080, "char*"));
    __dec_obj5 = come_decrement_ref_count(__dec_obj5, (void*)0, (void*)0, 0,0, (void*)0);
    self->buf[0]=0;
    self->len=0;
    __result_obj__28 = (struct buffer*)come_increment_ref_count(self);
    come_call_finalizer(buffer_finalize, self, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    come_call_finalizer(buffer_finalize, __result_obj__28, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__28;
}

struct buffer* buffer_initialize_with_value(struct buffer* self, char* mem, unsigned int size){
void* __right_value0 = (void*)0;
char* __dec_obj6;
struct buffer* __result_obj__29;
    self->size=128;
    __dec_obj6=self->buf,
    self->buf=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(self->size)), "/usr/local/include/comelang.h", 8090, "char*"));
    __dec_obj6 = come_decrement_ref_count(__dec_obj6, (void*)0, (void*)0, 0,0, (void*)0);
    self->buf[0]=0;
    self->len=0;
    buffer_append(self,mem,size);
    __result_obj__29 = (struct buffer*)come_increment_ref_count(self);
    come_call_finalizer(buffer_finalize, self, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    come_call_finalizer(buffer_finalize, __result_obj__29, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__29;
}

void buffer_finalize(struct buffer* self){
    if(    self&&self->buf    ) {
        (self->buf = come_decrement_ref_count(self->buf, (void*)0, (void*)0, 0, 0, (void*)0));
    }
}

struct buffer* buffer_clone(struct buffer* self){
struct buffer* __result_obj__30;
void* __right_value0 = (void*)0;
struct buffer* result;
char* __dec_obj7;
struct buffer* __result_obj__31;
    if(    self==((void*)0)    ) {
        __result_obj__30 = (void*)come_increment_ref_count(((void*)0));
        come_call_finalizer(buffer_finalize, __result_obj__30, (void*)0, (void*)0, 0, 0, 1, (void*)0);
        return __result_obj__30;
    }
    result=(struct buffer*)come_increment_ref_count((struct buffer*)come_calloc_v2(1, sizeof(struct buffer)*(1), "/usr/local/include/comelang.h", 8110, "struct buffer*"));
    result->size=self->size;
    __right_value0 = (void*)0;
    __dec_obj7=result->buf,
    result->buf=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(self->size)), "/usr/local/include/comelang.h", 8113, "char*"));
    __dec_obj7 = come_decrement_ref_count(__dec_obj7, (void*)0, (void*)0, 0,0, (void*)0);
    result->len=self->len;
    memcpy(result->buf,self->buf,self->len);
    __result_obj__31 = (struct buffer*)come_increment_ref_count(result);
    come_call_finalizer(buffer_finalize, result, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    come_call_finalizer(buffer_finalize, __result_obj__31, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__31;
}

_Bool buffer_equals(struct buffer* left, struct buffer* right){
void* __right_value0 = (void*)0;
void* __right_value1 = (void*)0;
_Bool __result_obj__32;
    if(    left==((void*)0)||right==((void*)0)    ) {
        return (_Bool)0;
    }
    __result_obj__32 = string_equals(((char*)(__right_value0=buffer_to_string(left))),((char*)(__right_value1=buffer_to_string(right))));
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__right_value1 = come_decrement_ref_count(__right_value1, (void*)0, (void*)0, 1, 0, (void*)0));
    return __result_obj__32;
}

int buffer_length(struct buffer* self){
    if(    self==((void*)0)    ) {
        return 0;
    }
    return self->len;
}

void buffer_reset(struct buffer* self){
    if(    self==((void*)0)    ) {
        return;
    }
    self->buf[0]=0;
    self->len=0;
}

void buffer_trim(struct buffer* self, int len){
    if(    self==((void*)0)    ) {
        return;
    }
    self->len-=len;
    self->buf[self->len]=0;
}

struct buffer* buffer_append(struct buffer* self, char* mem, unsigned int size){
struct buffer* __result_obj__33;
void* __right_value0 = (void*)0;
char* old_buf;
int old_len;
int new_size;
char* __dec_obj8;
struct buffer* __result_obj__34;
    if(    self==((void*)0)||mem==((void*)0)    ) {
        __result_obj__33 = self;
        return __result_obj__33;
    }
    if(    self->len+size+1+1>=self->size    ) {
        old_buf=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(self->size)), "/usr/local/include/comelang.h", 8161, "char*"));
        memcpy(old_buf,self->buf,self->size);
        old_len=self->len;
        new_size=(self->size+size+1)*2;
        __right_value0 = (void*)0;
        __dec_obj8=self->buf,
        self->buf=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(new_size)), "/usr/local/include/comelang.h", 8165, "char*"));
        __dec_obj8 = come_decrement_ref_count(__dec_obj8, (void*)0, (void*)0, 0,0, (void*)0);
        memcpy(self->buf,old_buf,old_len);
        self->buf[old_len]=0;
        self->size=new_size;
        (old_buf = come_decrement_ref_count(old_buf, (void*)0, (void*)0, 0, 0, (void*)0));
    }
    memcpy(self->buf+self->len,mem,size);
    self->len+=size;
    self->buf[self->len]=0;
    __result_obj__34 = self;
    return __result_obj__34;
}

struct buffer* buffer_append_char(struct buffer* self, char c){
struct buffer* __result_obj__35;
void* __right_value0 = (void*)0;
char* old_buf;
int old_len;
int new_size;
char* __dec_obj9;
struct buffer* __result_obj__36;
    if(    self==((void*)0)    ) {
        __result_obj__35 = ((void*)0);
        return __result_obj__35;
    }
    if(    self->len+1+1+1>=self->size    ) {
        old_buf=(char*)come_increment_ref_count((char*)come_memdup(self->buf, "/usr/local/include/comelang.h", 8184, "char*"));
        old_len=self->len;
        new_size=(self->size+10+1)*2;
        __right_value0 = (void*)0;
        __dec_obj9=self->buf,
        self->buf=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(new_size)), "/usr/local/include/comelang.h", 8188, "char*"));
        __dec_obj9 = come_decrement_ref_count(__dec_obj9, (void*)0, (void*)0, 0,0, (void*)0);
        memcpy(self->buf,old_buf,old_len);
        self->buf[old_len]=0;
        self->size=new_size;
        (old_buf = come_decrement_ref_count(old_buf, (void*)0, (void*)0, 0, 0, (void*)0));
    }
    self->buf[self->len]=c;
    self->len++;
    self->buf[self->len]=0;
    __result_obj__36 = self;
    return __result_obj__36;
}

struct buffer* buffer_append_str(struct buffer* self, char* mem){
struct buffer* __result_obj__37;
int size;
void* __right_value0 = (void*)0;
char* old_buf;
int old_len;
int new_size;
char* __dec_obj10;
struct buffer* __result_obj__38;
    if(    self==((void*)0)||mem==((void*)0)    ) {
        __result_obj__37 = self;
        return __result_obj__37;
    }
    size=strlen(mem);
    if(    self->len+size+1+1>=self->size    ) {
        old_buf=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(self->size)), "/usr/local/include/comelang.h", 8210, "char*"));
        memcpy(old_buf,self->buf,self->size);
        old_len=self->len;
        new_size=(self->size+size+1)*2;
        __right_value0 = (void*)0;
        __dec_obj10=self->buf,
        self->buf=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(new_size)), "/usr/local/include/comelang.h", 8214, "char*"));
        __dec_obj10 = come_decrement_ref_count(__dec_obj10, (void*)0, (void*)0, 0,0, (void*)0);
        memcpy(self->buf,old_buf,old_len);
        self->buf[old_len]=0;
        self->size=new_size;
        (old_buf = come_decrement_ref_count(old_buf, (void*)0, (void*)0, 0, 0, (void*)0));
    }
    memcpy(self->buf+self->len,mem,size);
    self->len+=size;
    self->buf[self->len]=0;
    __result_obj__38 = self;
    return __result_obj__38;
}

struct buffer* buffer_append_format(struct buffer* self, char* msg, ...){
struct buffer* __result_obj__39;
va_list args;
char* result;
int len;
struct buffer* __result_obj__40;
void* __right_value0 = (void*)0;
char* mem;
int size;
char* old_buf;
int old_len;
int new_size;
char* __dec_obj11;
struct buffer* __result_obj__41;
result = (void*)0;
    if(    self==((void*)0)||msg==((void*)0)    ) {
        __result_obj__39 = self;
        return __result_obj__39;
    }
    __builtin_va_start(args,msg);
    len=vasprintf(&result,msg,args);
    __builtin_va_end(args);
    if(    len<0    ) {
        __result_obj__40 = self;
        return __result_obj__40;
    }
    mem=(char*)come_increment_ref_count(__builtin_string(result));
    size=strlen(mem);
    if(    self->len+size+1+1>=self->size    ) {
        __right_value0 = (void*)0;
        old_buf=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(self->size)), "/usr/local/include/comelang.h", 8258, "char*"));
        memcpy(old_buf,self->buf,self->size);
        old_len=self->len;
        new_size=(self->size+size+1)*2;
        __right_value0 = (void*)0;
        __dec_obj11=self->buf,
        self->buf=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(new_size)), "/usr/local/include/comelang.h", 8262, "char*"));
        __dec_obj11 = come_decrement_ref_count(__dec_obj11, (void*)0, (void*)0, 0,0, (void*)0);
        memcpy(self->buf,old_buf,old_len);
        self->buf[old_len]=0;
        self->size=new_size;
        (old_buf = come_decrement_ref_count(old_buf, (void*)0, (void*)0, 0, 0, (void*)0));
    }
    memcpy(self->buf+self->len,mem,size);
    self->len+=size;
    self->buf[self->len]=0;
    free(result);
    __result_obj__41 = self;
    (mem = come_decrement_ref_count(mem, (void*)0, (void*)0, 0, 0, (void*)0));
    return __result_obj__41;
}

struct buffer* buffer_append_nullterminated_str(struct buffer* self, char* mem){
struct buffer* __result_obj__42;
int size;
void* __right_value0 = (void*)0;
char* old_buf;
int old_len;
int new_size;
char* __dec_obj12;
struct buffer* __result_obj__43;
    if(    self==((void*)0)||mem==((void*)0)    ) {
        __result_obj__42 = self;
        return __result_obj__42;
    }
    size=strlen(mem)+1;
    if(    self->len+size+1+1+1>=self->size    ) {
        old_buf=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(self->size)), "/usr/local/include/comelang.h", 8284, "char*"));
        memcpy(old_buf,self->buf,self->size);
        old_len=self->len;
        new_size=(self->size+size+1)*2;
        __right_value0 = (void*)0;
        __dec_obj12=self->buf,
        self->buf=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(new_size)), "/usr/local/include/comelang.h", 8288, "char*"));
        __dec_obj12 = come_decrement_ref_count(__dec_obj12, (void*)0, (void*)0, 0,0, (void*)0);
        memcpy(self->buf,old_buf,old_len);
        self->buf[old_len]=0;
        self->size=new_size;
        (old_buf = come_decrement_ref_count(old_buf, (void*)0, (void*)0, 0, 0, (void*)0));
    }
    memcpy(self->buf+self->len,mem,size);
    self->len+=size;
    self->buf[self->len]=0;
    self->len++;
    __result_obj__43 = self;
    return __result_obj__43;
}

struct buffer* buffer_append_int(struct buffer* self, int value){
struct buffer* __result_obj__44;
int* mem;
int size;
void* __right_value0 = (void*)0;
char* old_buf;
int old_len;
int new_size;
char* __dec_obj13;
struct buffer* __result_obj__45;
    if(    self==((void*)0)    ) {
        __result_obj__44 = ((void*)0);
        return __result_obj__44;
    }
    mem=&value;
    size=sizeof(int);
    if(    self->len+size+1+1>=self->size    ) {
        old_buf=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(self->size)), "/usr/local/include/comelang.h", 8311, "char*"));
        memcpy(old_buf,self->buf,self->size);
        old_len=self->len;
        new_size=(self->size+size+1)*2;
        __right_value0 = (void*)0;
        __dec_obj13=self->buf,
        self->buf=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(new_size)), "/usr/local/include/comelang.h", 8315, "char*"));
        __dec_obj13 = come_decrement_ref_count(__dec_obj13, (void*)0, (void*)0, 0,0, (void*)0);
        memcpy(self->buf,old_buf,old_len);
        self->buf[old_len]=0;
        self->size=new_size;
        (old_buf = come_decrement_ref_count(old_buf, (void*)0, (void*)0, 0, 0, (void*)0));
    }
    memcpy(self->buf+self->len,mem,size);
    self->len+=size;
    self->buf[self->len]=0;
    __result_obj__45 = self;
    return __result_obj__45;
}

struct buffer* buffer_append_long(struct buffer* self, long value){
long* mem;
int size;
void* __right_value0 = (void*)0;
char* old_buf;
int old_len;
int new_size;
char* __dec_obj14;
struct buffer* __result_obj__46;
    mem=&value;
    size=sizeof(long);
    if(    self->len+size+1+1>=self->size    ) {
        old_buf=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(self->size)), "/usr/local/include/comelang.h", 8334, "char*"));
        memcpy(old_buf,self->buf,self->size);
        old_len=self->len;
        new_size=(self->size+size+1)*2;
        __right_value0 = (void*)0;
        __dec_obj14=self->buf,
        self->buf=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(new_size)), "/usr/local/include/comelang.h", 8338, "char*"));
        __dec_obj14 = come_decrement_ref_count(__dec_obj14, (void*)0, (void*)0, 0,0, (void*)0);
        memcpy(self->buf,old_buf,old_len);
        self->buf[old_len]=0;
        self->size=new_size;
        (old_buf = come_decrement_ref_count(old_buf, (void*)0, (void*)0, 0, 0, (void*)0));
    }
    memcpy(self->buf+self->len,mem,size);
    self->len+=size;
    self->buf[self->len]=0;
    __result_obj__46 = self;
    return __result_obj__46;
}

struct buffer* buffer_append_short(struct buffer* self, short value){
struct buffer* __result_obj__47;
short* mem;
int size;
void* __right_value0 = (void*)0;
char* old_buf;
int old_len;
int new_size;
char* __dec_obj15;
struct buffer* __result_obj__48;
    if(    self==((void*)0)    ) {
        __result_obj__47 = ((void*)0);
        return __result_obj__47;
    }
    mem=&value;
    size=sizeof(short);
    if(    self->len+size+1+1>=self->size    ) {
        old_buf=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(self->size)), "/usr/local/include/comelang.h", 8361, "char*"));
        memcpy(old_buf,self->buf,self->size);
        old_len=self->len;
        new_size=(self->size+size+1)*2;
        __right_value0 = (void*)0;
        __dec_obj15=self->buf,
        self->buf=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(new_size)), "/usr/local/include/comelang.h", 8365, "char*"));
        __dec_obj15 = come_decrement_ref_count(__dec_obj15, (void*)0, (void*)0, 0,0, (void*)0);
        memcpy(self->buf,old_buf,old_len);
        self->buf[old_len]=0;
        self->size=new_size;
        (old_buf = come_decrement_ref_count(old_buf, (void*)0, (void*)0, 0, 0, (void*)0));
    }
    memcpy(self->buf+self->len,mem,size);
    self->len+=size;
    self->buf[self->len]=0;
    __result_obj__48 = self;
    return __result_obj__48;
}

struct buffer* buffer_alignment(struct buffer* self){
struct buffer* __result_obj__49;
int len;
int new_size;
void* __right_value0 = (void*)0;
char* __dec_obj16;
int i;
struct buffer* __result_obj__50;
    if(    self==((void*)0)    ) {
        __result_obj__49 = ((void*)0);
        return __result_obj__49;
    }
    len=self->len;
    len=(len+3)&~3;
    if(    len>=self->size    ) {
        new_size=(self->size+1+1)*2;
        __dec_obj16=self->buf,
        self->buf=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(new_size)), "/usr/local/include/comelang.h", 8389, "char*"));
        __dec_obj16 = come_decrement_ref_count(__dec_obj16, (void*)0, (void*)0, 0,0, (void*)0);
        self->size=new_size;
    }
    for(    i=self->len    ;    i<len    ;    i++    ){
        self->buf[i]=0;
    }
    self->len=len;
    __result_obj__50 = self;
    return __result_obj__50;
}

int buffer_compare(struct buffer* left, struct buffer* right){
    if(    left==((void*)0)&&right==((void*)0)    ) {
        return 0;
    }
    else if(    left==((void*)0)    ) {
        return -1;
    }
    else if(    right==((void*)0)    ) {
        return 1;
    }
    return strcmp(left->buf,right->buf);
}

struct buffer* charp_to_buffer(char* self){
void* __right_value0 = (void*)0;
void* __right_value1 = (void*)0;
struct buffer* result;
struct buffer* __result_obj__51;
struct buffer* __result_obj__52;
    result=(struct buffer*)come_increment_ref_count(buffer_initialize((struct buffer*)come_increment_ref_count((struct buffer*)come_calloc_v2(1, sizeof(struct buffer)*(1), "/usr/local/include/comelang.h", 8419, "struct buffer*"))));
    if(    self==((void*)0)    ) {
        __result_obj__51 = (struct buffer*)come_increment_ref_count(result);
        come_call_finalizer(buffer_finalize, result, (void*)0, (void*)0, 0, 0, 1, (void*)0);
        come_call_finalizer(buffer_finalize, __result_obj__51, (void*)0, (void*)0, 0, 0, 1, (void*)0);
        return __result_obj__51;
    }
    buffer_append_str(result,self);
    __result_obj__52 = (struct buffer*)come_increment_ref_count(result);
    come_call_finalizer(buffer_finalize, result, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    come_call_finalizer(buffer_finalize, __result_obj__52, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__52;
}

char* buffer_to_string(struct buffer* self){
void* __right_value0 = (void*)0;
char* __result_obj__53;
char* __result_obj__54;
    if(    self==((void*)0)    ) {
        __result_obj__53 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__53 = come_decrement_ref_count(__result_obj__53, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__53;
    }
    __right_value0 = (void*)0;
    __result_obj__54 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(self->buf))));
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__54 = come_decrement_ref_count(__result_obj__54, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__54;
}

unsigned char* buffer_head_pointer(struct buffer* self){
unsigned char* __result_obj__55;
    __result_obj__55 = self->buf;
    return __result_obj__55;
}

struct buffer* charpa_to_buffer(char* self, unsigned int len){
void* __right_value0 = (void*)0;
void* __right_value1 = (void*)0;
struct buffer* result;
struct buffer* __result_obj__56;
    result=(struct buffer*)come_increment_ref_count(buffer_initialize((struct buffer*)come_increment_ref_count((struct buffer*)come_calloc_v2(1, sizeof(struct buffer)*(1), "/usr/local/include/comelang.h", 8446, "struct buffer*"))));
    buffer_append(result,self,sizeof(char)*len);
    __result_obj__56 = (struct buffer*)come_increment_ref_count(result);
    come_call_finalizer(buffer_finalize, result, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    come_call_finalizer(buffer_finalize, __result_obj__56, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__56;
}

struct buffer* charppa_to_buffer(char** self, unsigned int len){
void* __right_value0 = (void*)0;
void* __right_value1 = (void*)0;
struct buffer* result;
int i;
struct buffer* __result_obj__57;
    result=(struct buffer*)come_increment_ref_count(buffer_initialize((struct buffer*)come_increment_ref_count((struct buffer*)come_calloc_v2(1, sizeof(struct buffer)*(1), "/usr/local/include/comelang.h", 8453, "struct buffer*"))));
    for(    i=0    ;    i<len    ;    i++    ){
        buffer_append(result,self[i],strlen(self[i]));
    }
    __result_obj__57 = (struct buffer*)come_increment_ref_count(result);
    come_call_finalizer(buffer_finalize, result, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    come_call_finalizer(buffer_finalize, __result_obj__57, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__57;
}

struct buffer* shortpa_to_buffer(short* self, unsigned int len){
void* __right_value0 = (void*)0;
void* __right_value1 = (void*)0;
struct buffer* result;
struct buffer* __result_obj__58;
    result=(struct buffer*)come_increment_ref_count(buffer_initialize((struct buffer*)come_increment_ref_count((struct buffer*)come_calloc_v2(1, sizeof(struct buffer)*(1), "/usr/local/include/comelang.h", 8462, "struct buffer*"))));
    buffer_append(result,(char*)self,sizeof(short)*len);
    __result_obj__58 = (struct buffer*)come_increment_ref_count(result);
    come_call_finalizer(buffer_finalize, result, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    come_call_finalizer(buffer_finalize, __result_obj__58, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__58;
}

struct buffer* intpa_to_buffer(int* self, unsigned int len){
void* __right_value0 = (void*)0;
void* __right_value1 = (void*)0;
struct buffer* result;
struct buffer* __result_obj__59;
    result=(struct buffer*)come_increment_ref_count(buffer_initialize((struct buffer*)come_increment_ref_count((struct buffer*)come_calloc_v2(1, sizeof(struct buffer)*(1), "/usr/local/include/comelang.h", 8469, "struct buffer*"))));
    buffer_append(result,(char*)self,sizeof(int)*len);
    __result_obj__59 = (struct buffer*)come_increment_ref_count(result);
    come_call_finalizer(buffer_finalize, result, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    come_call_finalizer(buffer_finalize, __result_obj__59, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__59;
}

struct buffer* longpa_to_buffer(long* self, unsigned int len){
void* __right_value0 = (void*)0;
void* __right_value1 = (void*)0;
struct buffer* result;
struct buffer* __result_obj__60;
    result=(struct buffer*)come_increment_ref_count(buffer_initialize((struct buffer*)come_increment_ref_count((struct buffer*)come_calloc_v2(1, sizeof(struct buffer)*(1), "/usr/local/include/comelang.h", 8476, "struct buffer*"))));
    buffer_append(result,(char*)self,sizeof(long)*len);
    __result_obj__60 = (struct buffer*)come_increment_ref_count(result);
    come_call_finalizer(buffer_finalize, result, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    come_call_finalizer(buffer_finalize, __result_obj__60, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__60;
}

struct buffer* floatpa_to_buffer(float* self, unsigned int len){
void* __right_value0 = (void*)0;
void* __right_value1 = (void*)0;
struct buffer* result;
struct buffer* __result_obj__61;
    result=(struct buffer*)come_increment_ref_count(buffer_initialize((struct buffer*)come_increment_ref_count((struct buffer*)come_calloc_v2(1, sizeof(struct buffer)*(1), "/usr/local/include/comelang.h", 8483, "struct buffer*"))));
    buffer_append(result,(char*)self,sizeof(float)*len);
    __result_obj__61 = (struct buffer*)come_increment_ref_count(result);
    come_call_finalizer(buffer_finalize, result, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    come_call_finalizer(buffer_finalize, __result_obj__61, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__61;
}

struct buffer* doublepa_to_buffer(double* self, unsigned int len){
void* __right_value0 = (void*)0;
void* __right_value1 = (void*)0;
struct buffer* result;
struct buffer* __result_obj__62;
    result=(struct buffer*)come_increment_ref_count(buffer_initialize((struct buffer*)come_increment_ref_count((struct buffer*)come_calloc_v2(1, sizeof(struct buffer)*(1), "/usr/local/include/comelang.h", 8490, "struct buffer*"))));
    buffer_append(result,(char*)self,sizeof(double)*len);
    __result_obj__62 = (struct buffer*)come_increment_ref_count(result);
    come_call_finalizer(buffer_finalize, result, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    come_call_finalizer(buffer_finalize, __result_obj__62, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__62;
}

char* buffer_printable(struct buffer* self){
int len;
void* __right_value0 = (void*)0;
char* result;
int n;
int i;
unsigned char c;
char* __result_obj__63;
    len=self->len;
    result=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(len*2+1)), "/usr/local/include/comelang.h", 8498, "char*"));
    n=0;
    for(    i=0    ;    i<len    ;    i++    ){
        c=self->buf[i];
        if(        (c>=0&&c<32)||c==127        ) {
            result[n++]=94;
            result[n++]=c+65-1;
        }
        else if(        c>127        ) {
            result[n++]=63;
        }
        else {
            result[n++]=c;
        }
    }
    result[n]=0;
    __result_obj__63 = (char*)come_increment_ref_count(result);
    (result = come_decrement_ref_count(result, (void*)0, (void*)0, 0, 1, (void*)0));
    (__result_obj__63 = come_decrement_ref_count(__result_obj__63, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__63;
}

static struct list$1char$* list$1char$_initialize_with_values(struct list$1char$* self, int num_value, char* values){
int i;
struct list$1char$* __result_obj__65;
    self->head=((void*)0);
    self->tail=((void*)0);
    self->len=0;
    for(    i=0    ;    i<num_value    ;    i++    ){
        list$1char$_push_back(self,values[i]);
    }
    __result_obj__65 = (struct list$1char$*)come_increment_ref_count(self);
    come_call_finalizer(list$1char$$p_finalize, self, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    come_call_finalizer(list$1char$$p_finalize, __result_obj__65, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__65;
}

static struct list$1char$* list$1char$_push_back(struct list$1char$* self, char item){
void* __right_value0 = (void*)0;
struct list_item$1char$* litem;
struct list_item$1char$* litem_8;
struct list_item$1char$* litem_9;
struct list$1char$* __result_obj__64;
    if(    self->len==0    ) {
        litem=(struct list_item$1char$*)come_increment_ref_count(((struct list_item$1char$*)(__right_value0=(struct list_item$1char$*)come_calloc_v2(1, sizeof(struct list_item$1char$)*(1), "/usr/local/include/comelang.h", 6239, "struct list_item$1char$*"))));
        litem->prev=((void*)0);
        litem->next=((void*)0);
        litem->item=item;
        self->tail=litem;
        self->head=litem;
    }
    else if(    self->len==1    ) {
        __right_value0 = (void*)0;
        litem_8=(struct list_item$1char$*)come_increment_ref_count(((struct list_item$1char$*)(__right_value0=(struct list_item$1char$*)come_calloc_v2(1, sizeof(struct list_item$1char$)*(1), "/usr/local/include/comelang.h", 6249, "struct list_item$1char$*"))));
        litem_8->prev=self->head;
        litem_8->next=((void*)0);
        litem_8->item=item;
        self->tail=litem_8;
        self->head->next=litem_8;
    }
    else {
        __right_value0 = (void*)0;
        litem_9=(struct list_item$1char$*)come_increment_ref_count(((struct list_item$1char$*)(__right_value0=(struct list_item$1char$*)come_calloc_v2(1, sizeof(struct list_item$1char$)*(1), "/usr/local/include/comelang.h", 6259, "struct list_item$1char$*"))));
        litem_9->prev=self->tail;
        litem_9->next=((void*)0);
        litem_9->item=item;
        self->tail->next=litem_9;
        self->tail=litem_9;
    }
    self->len++;
    __result_obj__64 = self;
    return __result_obj__64;
}

static void list$1char$$p_finalize(struct list$1char$* self){
struct list_item$1char$* it;
struct list_item$1char$* prev_it;
    it=self->head;
    while(    it!=((void*)0)    ) {
        prev_it=it;
        it=it->next;
        come_call_finalizer(list_item$1char$$p_finalize, prev_it, (void*)0, (void*)0, 0, 0, 0, (void*)0);
    }
}

static void list_item$1char$$p_finalize(struct list_item$1char$* self){
}

struct list$1char$* charpa_to_list(char* self, unsigned int len){
void* __right_value0 = (void*)0;
void* __right_value1 = (void*)0;
struct list$1char$* __result_obj__66;
    __result_obj__66 = (struct list$1char$*)come_increment_ref_count(((struct list$1char$*)(__right_value1=list$1char$_initialize_with_values((struct list$1char$*)come_increment_ref_count((struct list$1char$*)come_calloc_v2(1, sizeof(struct list$1char$)*(1), "/usr/local/include/comelang.h", 8539, "struct list$1char$*")),len,self))));
    come_call_finalizer(list$1char$$p_finalize, __right_value1, (void*)0, (void*)0, 0, 1, 0, (void*)0);
    come_call_finalizer(list$1char$$p_finalize, __result_obj__66, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__66;
}

static struct list$1char$p* list$1char$p_initialize_with_values(struct list$1char$p* self, int num_value, char** values){
int i;
struct list$1char$p* __result_obj__68;
    self->head=((void*)0);
    self->tail=((void*)0);
    self->len=0;
    for(    i=0    ;    i<num_value    ;    i++    ){
        list$1char$p_push_back(self,values[i]);
    }
    __result_obj__68 = (struct list$1char$p*)come_increment_ref_count(self);
    come_call_finalizer(list$1char$p$p_finalize, self, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    come_call_finalizer(list$1char$p$p_finalize, __result_obj__68, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__68;
}

static struct list$1char$p* list$1char$p_push_back(struct list$1char$p* self, char* item){
void* __right_value0 = (void*)0;
struct list_item$1char$p* litem;
struct list_item$1char$p* litem_10;
struct list_item$1char$p* litem_11;
struct list$1char$p* __result_obj__67;
    if(    self->len==0    ) {
        litem=(struct list_item$1char$p*)come_increment_ref_count(((struct list_item$1char$p*)(__right_value0=(struct list_item$1char$p*)come_calloc_v2(1, sizeof(struct list_item$1char$p)*(1), "/usr/local/include/comelang.h", 6239, "struct list_item$1char$p*"))));
        litem->prev=((void*)0);
        litem->next=((void*)0);
        litem->item=item;
        self->tail=litem;
        self->head=litem;
    }
    else if(    self->len==1    ) {
        __right_value0 = (void*)0;
        litem_10=(struct list_item$1char$p*)come_increment_ref_count(((struct list_item$1char$p*)(__right_value0=(struct list_item$1char$p*)come_calloc_v2(1, sizeof(struct list_item$1char$p)*(1), "/usr/local/include/comelang.h", 6249, "struct list_item$1char$p*"))));
        litem_10->prev=self->head;
        litem_10->next=((void*)0);
        litem_10->item=item;
        self->tail=litem_10;
        self->head->next=litem_10;
    }
    else {
        __right_value0 = (void*)0;
        litem_11=(struct list_item$1char$p*)come_increment_ref_count(((struct list_item$1char$p*)(__right_value0=(struct list_item$1char$p*)come_calloc_v2(1, sizeof(struct list_item$1char$p)*(1), "/usr/local/include/comelang.h", 6259, "struct list_item$1char$p*"))));
        litem_11->prev=self->tail;
        litem_11->next=((void*)0);
        litem_11->item=item;
        self->tail->next=litem_11;
        self->tail=litem_11;
    }
    self->len++;
    __result_obj__67 = self;
    return __result_obj__67;
}

static void list$1char$p$p_finalize(struct list$1char$p* self){
struct list_item$1char$p* it;
struct list_item$1char$p* prev_it;
    it=self->head;
    while(    it!=((void*)0)    ) {
        prev_it=it;
        it=it->next;
        come_call_finalizer(list_item$1char$p$p_finalize, prev_it, (void*)0, (void*)0, 0, 0, 0, (void*)0);
    }
}

static void list_item$1char$p$p_finalize(struct list_item$1char$p* self){
}

struct list$1char$p* charppa_to_list(char** self, unsigned int len){
void* __right_value0 = (void*)0;
void* __right_value1 = (void*)0;
struct list$1char$p* __result_obj__69;
    __result_obj__69 = (struct list$1char$p*)come_increment_ref_count(((struct list$1char$p*)(__right_value1=list$1char$p_initialize_with_values((struct list$1char$p*)come_increment_ref_count((struct list$1char$p*)come_calloc_v2(1, sizeof(struct list$1char$p)*(1), "/usr/local/include/comelang.h", 8544, "struct list$1char$p*")),len,self))));
    come_call_finalizer(list$1char$p$p_finalize, __right_value1, (void*)0, (void*)0, 0, 1, 0, (void*)0);
    come_call_finalizer(list$1char$p$p_finalize, __result_obj__69, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__69;
}

static struct list$1short$* list$1short$_initialize_with_values(struct list$1short$* self, int num_value, short* values){
int i;
struct list$1short$* __result_obj__71;
    self->head=((void*)0);
    self->tail=((void*)0);
    self->len=0;
    for(    i=0    ;    i<num_value    ;    i++    ){
        list$1short$_push_back(self,values[i]);
    }
    __result_obj__71 = (struct list$1short$*)come_increment_ref_count(self);
    come_call_finalizer(list$1short$$p_finalize, self, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    come_call_finalizer(list$1short$$p_finalize, __result_obj__71, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__71;
}

static struct list$1short$* list$1short$_push_back(struct list$1short$* self, short item){
void* __right_value0 = (void*)0;
struct list_item$1short$* litem;
struct list_item$1short$* litem_12;
struct list_item$1short$* litem_13;
struct list$1short$* __result_obj__70;
    if(    self->len==0    ) {
        litem=(struct list_item$1short$*)come_increment_ref_count(((struct list_item$1short$*)(__right_value0=(struct list_item$1short$*)come_calloc_v2(1, sizeof(struct list_item$1short$)*(1), "/usr/local/include/comelang.h", 6239, "struct list_item$1short$*"))));
        litem->prev=((void*)0);
        litem->next=((void*)0);
        litem->item=item;
        self->tail=litem;
        self->head=litem;
    }
    else if(    self->len==1    ) {
        __right_value0 = (void*)0;
        litem_12=(struct list_item$1short$*)come_increment_ref_count(((struct list_item$1short$*)(__right_value0=(struct list_item$1short$*)come_calloc_v2(1, sizeof(struct list_item$1short$)*(1), "/usr/local/include/comelang.h", 6249, "struct list_item$1short$*"))));
        litem_12->prev=self->head;
        litem_12->next=((void*)0);
        litem_12->item=item;
        self->tail=litem_12;
        self->head->next=litem_12;
    }
    else {
        __right_value0 = (void*)0;
        litem_13=(struct list_item$1short$*)come_increment_ref_count(((struct list_item$1short$*)(__right_value0=(struct list_item$1short$*)come_calloc_v2(1, sizeof(struct list_item$1short$)*(1), "/usr/local/include/comelang.h", 6259, "struct list_item$1short$*"))));
        litem_13->prev=self->tail;
        litem_13->next=((void*)0);
        litem_13->item=item;
        self->tail->next=litem_13;
        self->tail=litem_13;
    }
    self->len++;
    __result_obj__70 = self;
    return __result_obj__70;
}

static void list$1short$$p_finalize(struct list$1short$* self){
struct list_item$1short$* it;
struct list_item$1short$* prev_it;
    it=self->head;
    while(    it!=((void*)0)    ) {
        prev_it=it;
        it=it->next;
        come_call_finalizer(list_item$1short$$p_finalize, prev_it, (void*)0, (void*)0, 0, 0, 0, (void*)0);
    }
}

static void list_item$1short$$p_finalize(struct list_item$1short$* self){
}

struct list$1short$* shortpa_to_list(short* self, unsigned int len){
void* __right_value0 = (void*)0;
void* __right_value1 = (void*)0;
struct list$1short$* __result_obj__72;
    __result_obj__72 = (struct list$1short$*)come_increment_ref_count(((struct list$1short$*)(__right_value1=list$1short$_initialize_with_values((struct list$1short$*)come_increment_ref_count((struct list$1short$*)come_calloc_v2(1, sizeof(struct list$1short$)*(1), "/usr/local/include/comelang.h", 8549, "struct list$1short$*")),len,self))));
    come_call_finalizer(list$1short$$p_finalize, __right_value1, (void*)0, (void*)0, 0, 1, 0, (void*)0);
    come_call_finalizer(list$1short$$p_finalize, __result_obj__72, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__72;
}

static struct list$1int$* list$1int$_initialize_with_values(struct list$1int$* self, int num_value, int* values){
int i;
struct list$1int$* __result_obj__74;
    self->head=((void*)0);
    self->tail=((void*)0);
    self->len=0;
    for(    i=0    ;    i<num_value    ;    i++    ){
        list$1int$_push_back(self,values[i]);
    }
    __result_obj__74 = (struct list$1int$*)come_increment_ref_count(self);
    come_call_finalizer(list$1int$$p_finalize, self, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    come_call_finalizer(list$1int$$p_finalize, __result_obj__74, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__74;
}

static struct list$1int$* list$1int$_push_back(struct list$1int$* self, int item){
void* __right_value0 = (void*)0;
struct list_item$1int$* litem;
struct list_item$1int$* litem_14;
struct list_item$1int$* litem_15;
struct list$1int$* __result_obj__73;
    if(    self->len==0    ) {
        litem=(struct list_item$1int$*)come_increment_ref_count(((struct list_item$1int$*)(__right_value0=(struct list_item$1int$*)come_calloc_v2(1, sizeof(struct list_item$1int$)*(1), "/usr/local/include/comelang.h", 6239, "struct list_item$1int$*"))));
        litem->prev=((void*)0);
        litem->next=((void*)0);
        litem->item=item;
        self->tail=litem;
        self->head=litem;
    }
    else if(    self->len==1    ) {
        __right_value0 = (void*)0;
        litem_14=(struct list_item$1int$*)come_increment_ref_count(((struct list_item$1int$*)(__right_value0=(struct list_item$1int$*)come_calloc_v2(1, sizeof(struct list_item$1int$)*(1), "/usr/local/include/comelang.h", 6249, "struct list_item$1int$*"))));
        litem_14->prev=self->head;
        litem_14->next=((void*)0);
        litem_14->item=item;
        self->tail=litem_14;
        self->head->next=litem_14;
    }
    else {
        __right_value0 = (void*)0;
        litem_15=(struct list_item$1int$*)come_increment_ref_count(((struct list_item$1int$*)(__right_value0=(struct list_item$1int$*)come_calloc_v2(1, sizeof(struct list_item$1int$)*(1), "/usr/local/include/comelang.h", 6259, "struct list_item$1int$*"))));
        litem_15->prev=self->tail;
        litem_15->next=((void*)0);
        litem_15->item=item;
        self->tail->next=litem_15;
        self->tail=litem_15;
    }
    self->len++;
    __result_obj__73 = self;
    return __result_obj__73;
}

static void list$1int$$p_finalize(struct list$1int$* self){
struct list_item$1int$* it;
struct list_item$1int$* prev_it;
    it=self->head;
    while(    it!=((void*)0)    ) {
        prev_it=it;
        it=it->next;
        come_call_finalizer(list_item$1int$$p_finalize, prev_it, (void*)0, (void*)0, 0, 0, 0, (void*)0);
    }
}

static void list_item$1int$$p_finalize(struct list_item$1int$* self){
}

struct list$1int$* intpa_to_list(int* self, unsigned int len){
void* __right_value0 = (void*)0;
void* __right_value1 = (void*)0;
struct list$1int$* __result_obj__75;
    __result_obj__75 = (struct list$1int$*)come_increment_ref_count(((struct list$1int$*)(__right_value1=list$1int$_initialize_with_values((struct list$1int$*)come_increment_ref_count((struct list$1int$*)come_calloc_v2(1, sizeof(struct list$1int$)*(1), "/usr/local/include/comelang.h", 8554, "struct list$1int$*")),len,self))));
    come_call_finalizer(list$1int$$p_finalize, __right_value1, (void*)0, (void*)0, 0, 1, 0, (void*)0);
    come_call_finalizer(list$1int$$p_finalize, __result_obj__75, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__75;
}

static struct list$1long$* list$1long$_initialize_with_values(struct list$1long$* self, int num_value, long* values){
int i;
struct list$1long$* __result_obj__77;
    self->head=((void*)0);
    self->tail=((void*)0);
    self->len=0;
    for(    i=0    ;    i<num_value    ;    i++    ){
        list$1long$_push_back(self,values[i]);
    }
    __result_obj__77 = (struct list$1long$*)come_increment_ref_count(self);
    come_call_finalizer(list$1long$$p_finalize, self, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    come_call_finalizer(list$1long$$p_finalize, __result_obj__77, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__77;
}

static struct list$1long$* list$1long$_push_back(struct list$1long$* self, long item){
void* __right_value0 = (void*)0;
struct list_item$1long$* litem;
struct list_item$1long$* litem_16;
struct list_item$1long$* litem_17;
struct list$1long$* __result_obj__76;
    if(    self->len==0    ) {
        litem=(struct list_item$1long$*)come_increment_ref_count(((struct list_item$1long$*)(__right_value0=(struct list_item$1long$*)come_calloc_v2(1, sizeof(struct list_item$1long$)*(1), "/usr/local/include/comelang.h", 6239, "struct list_item$1long$*"))));
        litem->prev=((void*)0);
        litem->next=((void*)0);
        litem->item=item;
        self->tail=litem;
        self->head=litem;
    }
    else if(    self->len==1    ) {
        __right_value0 = (void*)0;
        litem_16=(struct list_item$1long$*)come_increment_ref_count(((struct list_item$1long$*)(__right_value0=(struct list_item$1long$*)come_calloc_v2(1, sizeof(struct list_item$1long$)*(1), "/usr/local/include/comelang.h", 6249, "struct list_item$1long$*"))));
        litem_16->prev=self->head;
        litem_16->next=((void*)0);
        litem_16->item=item;
        self->tail=litem_16;
        self->head->next=litem_16;
    }
    else {
        __right_value0 = (void*)0;
        litem_17=(struct list_item$1long$*)come_increment_ref_count(((struct list_item$1long$*)(__right_value0=(struct list_item$1long$*)come_calloc_v2(1, sizeof(struct list_item$1long$)*(1), "/usr/local/include/comelang.h", 6259, "struct list_item$1long$*"))));
        litem_17->prev=self->tail;
        litem_17->next=((void*)0);
        litem_17->item=item;
        self->tail->next=litem_17;
        self->tail=litem_17;
    }
    self->len++;
    __result_obj__76 = self;
    return __result_obj__76;
}

static void list$1long$$p_finalize(struct list$1long$* self){
struct list_item$1long$* it;
struct list_item$1long$* prev_it;
    it=self->head;
    while(    it!=((void*)0)    ) {
        prev_it=it;
        it=it->next;
        come_call_finalizer(list_item$1long$$p_finalize, prev_it, (void*)0, (void*)0, 0, 0, 0, (void*)0);
    }
}

static void list_item$1long$$p_finalize(struct list_item$1long$* self){
}

struct list$1long$* longpa_to_list(long* self, unsigned int len){
void* __right_value0 = (void*)0;
void* __right_value1 = (void*)0;
struct list$1long$* __result_obj__78;
    __result_obj__78 = (struct list$1long$*)come_increment_ref_count(((struct list$1long$*)(__right_value1=list$1long$_initialize_with_values((struct list$1long$*)come_increment_ref_count((struct list$1long$*)come_calloc_v2(1, sizeof(struct list$1long$)*(1), "/usr/local/include/comelang.h", 8559, "struct list$1long$*")),len,self))));
    come_call_finalizer(list$1long$$p_finalize, __right_value1, (void*)0, (void*)0, 0, 1, 0, (void*)0);
    come_call_finalizer(list$1long$$p_finalize, __result_obj__78, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__78;
}

static struct list$1float$* list$1float$_initialize_with_values(struct list$1float$* self, int num_value, float* values){
int i;
struct list$1float$* __result_obj__80;
    self->head=((void*)0);
    self->tail=((void*)0);
    self->len=0;
    for(    i=0    ;    i<num_value    ;    i++    ){
        list$1float$_push_back(self,values[i]);
    }
    __result_obj__80 = (struct list$1float$*)come_increment_ref_count(self);
    come_call_finalizer(list$1float$$p_finalize, self, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    come_call_finalizer(list$1float$$p_finalize, __result_obj__80, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__80;
}

static struct list$1float$* list$1float$_push_back(struct list$1float$* self, float item){
void* __right_value0 = (void*)0;
struct list_item$1float$* litem;
struct list_item$1float$* litem_18;
struct list_item$1float$* litem_19;
struct list$1float$* __result_obj__79;
    if(    self->len==0    ) {
        litem=(struct list_item$1float$*)come_increment_ref_count(((struct list_item$1float$*)(__right_value0=(struct list_item$1float$*)come_calloc_v2(1, sizeof(struct list_item$1float$)*(1), "/usr/local/include/comelang.h", 6239, "struct list_item$1float$*"))));
        litem->prev=((void*)0);
        litem->next=((void*)0);
        litem->item=item;
        self->tail=litem;
        self->head=litem;
    }
    else if(    self->len==1    ) {
        __right_value0 = (void*)0;
        litem_18=(struct list_item$1float$*)come_increment_ref_count(((struct list_item$1float$*)(__right_value0=(struct list_item$1float$*)come_calloc_v2(1, sizeof(struct list_item$1float$)*(1), "/usr/local/include/comelang.h", 6249, "struct list_item$1float$*"))));
        litem_18->prev=self->head;
        litem_18->next=((void*)0);
        litem_18->item=item;
        self->tail=litem_18;
        self->head->next=litem_18;
    }
    else {
        __right_value0 = (void*)0;
        litem_19=(struct list_item$1float$*)come_increment_ref_count(((struct list_item$1float$*)(__right_value0=(struct list_item$1float$*)come_calloc_v2(1, sizeof(struct list_item$1float$)*(1), "/usr/local/include/comelang.h", 6259, "struct list_item$1float$*"))));
        litem_19->prev=self->tail;
        litem_19->next=((void*)0);
        litem_19->item=item;
        self->tail->next=litem_19;
        self->tail=litem_19;
    }
    self->len++;
    __result_obj__79 = self;
    return __result_obj__79;
}

static void list$1float$$p_finalize(struct list$1float$* self){
struct list_item$1float$* it;
struct list_item$1float$* prev_it;
    it=self->head;
    while(    it!=((void*)0)    ) {
        prev_it=it;
        it=it->next;
        come_call_finalizer(list_item$1float$$p_finalize, prev_it, (void*)0, (void*)0, 0, 0, 0, (void*)0);
    }
}

static void list_item$1float$$p_finalize(struct list_item$1float$* self){
}

struct list$1float$* floatpa_to_list(float* self, unsigned int len){
void* __right_value0 = (void*)0;
void* __right_value1 = (void*)0;
struct list$1float$* __result_obj__81;
    __result_obj__81 = (struct list$1float$*)come_increment_ref_count(((struct list$1float$*)(__right_value1=list$1float$_initialize_with_values((struct list$1float$*)come_increment_ref_count((struct list$1float$*)come_calloc_v2(1, sizeof(struct list$1float$)*(1), "/usr/local/include/comelang.h", 8564, "struct list$1float$*")),len,self))));
    come_call_finalizer(list$1float$$p_finalize, __right_value1, (void*)0, (void*)0, 0, 1, 0, (void*)0);
    come_call_finalizer(list$1float$$p_finalize, __result_obj__81, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__81;
}

static struct list$1double$* list$1double$_initialize_with_values(struct list$1double$* self, int num_value, double* values){
int i;
struct list$1double$* __result_obj__83;
    self->head=((void*)0);
    self->tail=((void*)0);
    self->len=0;
    for(    i=0    ;    i<num_value    ;    i++    ){
        list$1double$_push_back(self,values[i]);
    }
    __result_obj__83 = (struct list$1double$*)come_increment_ref_count(self);
    come_call_finalizer(list$1double$$p_finalize, self, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    come_call_finalizer(list$1double$$p_finalize, __result_obj__83, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__83;
}

static struct list$1double$* list$1double$_push_back(struct list$1double$* self, double item){
void* __right_value0 = (void*)0;
struct list_item$1double$* litem;
struct list_item$1double$* litem_20;
struct list_item$1double$* litem_21;
struct list$1double$* __result_obj__82;
    if(    self->len==0    ) {
        litem=(struct list_item$1double$*)come_increment_ref_count(((struct list_item$1double$*)(__right_value0=(struct list_item$1double$*)come_calloc_v2(1, sizeof(struct list_item$1double$)*(1), "/usr/local/include/comelang.h", 6239, "struct list_item$1double$*"))));
        litem->prev=((void*)0);
        litem->next=((void*)0);
        litem->item=item;
        self->tail=litem;
        self->head=litem;
    }
    else if(    self->len==1    ) {
        __right_value0 = (void*)0;
        litem_20=(struct list_item$1double$*)come_increment_ref_count(((struct list_item$1double$*)(__right_value0=(struct list_item$1double$*)come_calloc_v2(1, sizeof(struct list_item$1double$)*(1), "/usr/local/include/comelang.h", 6249, "struct list_item$1double$*"))));
        litem_20->prev=self->head;
        litem_20->next=((void*)0);
        litem_20->item=item;
        self->tail=litem_20;
        self->head->next=litem_20;
    }
    else {
        __right_value0 = (void*)0;
        litem_21=(struct list_item$1double$*)come_increment_ref_count(((struct list_item$1double$*)(__right_value0=(struct list_item$1double$*)come_calloc_v2(1, sizeof(struct list_item$1double$)*(1), "/usr/local/include/comelang.h", 6259, "struct list_item$1double$*"))));
        litem_21->prev=self->tail;
        litem_21->next=((void*)0);
        litem_21->item=item;
        self->tail->next=litem_21;
        self->tail=litem_21;
    }
    self->len++;
    __result_obj__82 = self;
    return __result_obj__82;
}

static void list$1double$$p_finalize(struct list$1double$* self){
struct list_item$1double$* it;
struct list_item$1double$* prev_it;
    it=self->head;
    while(    it!=((void*)0)    ) {
        prev_it=it;
        it=it->next;
        come_call_finalizer(list_item$1double$$p_finalize, prev_it, (void*)0, (void*)0, 0, 0, 0, (void*)0);
    }
}

static void list_item$1double$$p_finalize(struct list_item$1double$* self){
}

struct list$1double$* doublepa_to_list(double* self, unsigned int len){
void* __right_value0 = (void*)0;
void* __right_value1 = (void*)0;
struct list$1double$* __result_obj__84;
    __result_obj__84 = (struct list$1double$*)come_increment_ref_count(((struct list$1double$*)(__right_value1=list$1double$_initialize_with_values((struct list$1double$*)come_increment_ref_count((struct list$1double$*)come_calloc_v2(1, sizeof(struct list$1double$)*(1), "/usr/local/include/comelang.h", 8569, "struct list$1double$*")),len,self))));
    come_call_finalizer(list$1double$$p_finalize, __right_value1, (void*)0, (void*)0, 0, 1, 0, (void*)0);
    come_call_finalizer(list$1double$$p_finalize, __result_obj__84, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__84;
}

_Bool bool_equals(_Bool self, _Bool right){
    return self==right;
}

_Bool _Bool_equals(_Bool self, _Bool right){
    return self==right;
}

_Bool char_equals(char self, char right){
    return self==right;
}

_Bool short_equals(short self, short right){
    return self==right;
}

_Bool int_equals(int self, int right){
    return self==right;
}

_Bool long_equals(long self, long right){
    return self==right;
}

_Bool size_t_equals(unsigned int self, unsigned int right){
    return self==right;
}

_Bool float_equals(float self, float right){
    return self==right;
}

_Bool double_equals(double self, double right){
    return self==right;
}

_Bool bool_operator_equals(_Bool self, _Bool right){
    return self==right;
}

_Bool _Bool_operator_equals(_Bool self, _Bool right){
    return self==right;
}

_Bool char_operator_equals(char self, char right){
    return self==right;
}

_Bool short_operator_equals(short self, short right){
    return self==right;
}

_Bool int_operator_equals(int self, int right){
    return self==right;
}

_Bool long_operator_equals(long self, long right){
    return self==right;
}

_Bool bool_operator_not_equals(_Bool self, _Bool right){
    return !(self==right);
}

_Bool _Bool_operator_not_equals(_Bool self, _Bool right){
    return !(self==right);
}

_Bool char_operator_not_equals(char self, char right){
    return !(self==right);
}

_Bool short_operator_not_equals(short self, short right){
    return !(self==right);
}

_Bool int_operator_not_equals(int self, int right){
    return !(self==right);
}

_Bool long_operator_not_equals(long self, long right){
    return !(self==right);
}

_Bool charp_equals(char* self, char* right){
    if(    self==((void*)0)&&right==((void*)0)    ) {
        return (_Bool)1;
    }
    else if(    self==((void*)0)    ) {
        return (_Bool)0;
    }
    else if(    right==((void*)0)    ) {
        return (_Bool)0;
    }
    return strcmp(self,right)==0;
}

_Bool string_equals(char* self, char* right){
    if(    self==((void*)0)&&right==((void*)0)    ) {
        return (_Bool)1;
    }
    else if(    self==((void*)0)    ) {
        return (_Bool)0;
    }
    else if(    right==((void*)0)    ) {
        return (_Bool)0;
    }
    return strcmp(self,right)==0;
}

_Bool voidp_equals(void* self, void* right){
    return self==right;
}

_Bool boolp_equals(_Bool* self, _Bool* right){
    return *self==*right;
}

_Bool string_operator_equals(char* self, char* right){
    if(    self==((void*)0)&&right==((void*)0)    ) {
        return (_Bool)1;
    }
    else if(    self==((void*)0)    ) {
        return (_Bool)0;
    }
    else if(    right==((void*)0)    ) {
        return (_Bool)0;
    }
    return strcmp(self,right)==0;
}

_Bool charp_operator_equals(char* self, char* right){
    if(    self==((void*)0)&&right==((void*)0)    ) {
        return (_Bool)1;
    }
    else if(    self==((void*)0)    ) {
        return (_Bool)0;
    }
    else if(    right==((void*)0)    ) {
        return (_Bool)0;
    }
    return strcmp(self,right)==0;
}

_Bool voidp_operator_equals(char* self, char* right){
    return self==right;
}

_Bool voidp_operator_not_equals(char* self, char* right){
    return !charp_operator_equals(self,right);
}

_Bool string_operator_not_equals(char* self, char* right){
    if(    self==((void*)0)&&right==((void*)0)    ) {
        return (_Bool)0;
    }
    else if(    self==((void*)0)    ) {
        return (_Bool)1;
    }
    else if(    right==((void*)0)    ) {
        return (_Bool)1;
    }
    return strcmp(self,right)!=0;
}

_Bool charp_operator_not_equals(char* self, char* right){
    if(    self==((void*)0)&&right==((void*)0)    ) {
        return (_Bool)0;
    }
    else if(    self==((void*)0)    ) {
        return (_Bool)1;
    }
    else if(    right==((void*)0)    ) {
        return (_Bool)1;
    }
    return strcmp(self,right)!=0;
}

char* charp_operator_add(char* self, char* right){
void* __right_value0 = (void*)0;
char* __result_obj__85;
int len;
char* result;
char* __result_obj__86;
    if(    self==((void*)0)||right==((void*)0)    ) {
        __result_obj__85 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__85 = come_decrement_ref_count(__result_obj__85, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__85;
    }
    len=strlen(self)+strlen(right);
    __right_value0 = (void*)0;
    result=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(len+1)), "/usr/local/include/comelang.h", 8798, "char*"));
    strncpy(result,self,len+1);
    strncat(result,right,len+1);
    __result_obj__86 = (char*)come_increment_ref_count(result);
    (result = come_decrement_ref_count(result, (void*)0, (void*)0, 0, 1, (void*)0));
    (__result_obj__86 = come_decrement_ref_count(__result_obj__86, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__86;
}

char* string_operator_add(char* self, char* right){
void* __right_value0 = (void*)0;
char* __result_obj__87;
int len;
char* result;
char* __result_obj__88;
    if(    self==((void*)0)||right==((void*)0)    ) {
        __result_obj__87 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__87 = come_decrement_ref_count(__result_obj__87, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__87;
    }
    len=strlen(self)+strlen(right);
    __right_value0 = (void*)0;
    result=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(len+1)), "/usr/local/include/comelang.h", 8813, "char*"));
    strncpy(result,self,len+1);
    strncat(result,right,len+1);
    __result_obj__88 = (char*)come_increment_ref_count(result);
    (result = come_decrement_ref_count(result, (void*)0, (void*)0, 0, 1, (void*)0));
    (__result_obj__88 = come_decrement_ref_count(__result_obj__88, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__88;
}

char* charp_operator_mult(char* self, int right){
void* __right_value0 = (void*)0;
char* __result_obj__89;
void* __right_value1 = (void*)0;
struct buffer* buf;
int i;
char* __result_obj__90;
    if(    self==((void*)0)    ) {
        __result_obj__89 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__89 = come_decrement_ref_count(__result_obj__89, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__89;
    }
    __right_value0 = (void*)0;
    buf=(struct buffer*)come_increment_ref_count(buffer_initialize((struct buffer*)come_increment_ref_count((struct buffer*)come_calloc_v2(1, sizeof(struct buffer)*(1), "/usr/local/include/comelang.h", 8826, "struct buffer*"))));
    for(    i=0    ;    i<right    ;    i++    ){
        buffer_append_str(buf,self);
    }
    __right_value0 = (void*)0;
    __result_obj__90 = (char*)come_increment_ref_count(((char*)(__right_value0=buffer_to_string(buf))));
    come_call_finalizer(buffer_finalize, buf, (void*)0, (void*)0, 0, 0, 0, (void*)0);
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__90 = come_decrement_ref_count(__result_obj__90, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__90;
}

char* string_operator_mult(char* self, int right){
void* __right_value0 = (void*)0;
char* __result_obj__91;
void* __right_value1 = (void*)0;
struct buffer* buf;
int i;
char* __result_obj__92;
    if(    self==((void*)0)    ) {
        __result_obj__91 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__91 = come_decrement_ref_count(__result_obj__91, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__91;
    }
    __right_value0 = (void*)0;
    buf=(struct buffer*)come_increment_ref_count(buffer_initialize((struct buffer*)come_increment_ref_count((struct buffer*)come_calloc_v2(1, sizeof(struct buffer)*(1), "/usr/local/include/comelang.h", 8840, "struct buffer*"))));
    for(    i=0    ;    i<right    ;    i++    ){
        buffer_append_str(buf,self);
    }
    __right_value0 = (void*)0;
    __result_obj__92 = (char*)come_increment_ref_count(((char*)(__right_value0=buffer_to_string(buf))));
    come_call_finalizer(buffer_finalize, buf, (void*)0, (void*)0, 0, 0, 0, (void*)0);
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__92 = come_decrement_ref_count(__result_obj__92, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__92;
}

unsigned int charpa_length(char* self, unsigned int len){
    return len;
}

_Bool charppa_contained(char** self, unsigned int len, char* str){
_Bool result;
int i;
    result=(_Bool)0;
    for(    i=0    ;    i<len    ;    i++    ){
        if(        strncmp(self[i],str,strlen(self[i]))==0        ) {
            result=(_Bool)1;
            break;
        }
    }
    return result;
}

unsigned int shortpa_length(short* self, unsigned int len){
    return len;
}

unsigned int intpa_length(int* self, unsigned int len){
    return len;
}

unsigned int longpa_length(long* self, unsigned int len){
    return len;
}

unsigned int floatpa_length(float* self, unsigned int len){
    return len;
}

unsigned int doublepa_length(double* self, unsigned int len){
    return len;
}

unsigned int bool_get_hash_key(_Bool value){
    return (int_get_hash_key(((int)value)));
}

unsigned int _Bool_get_hash_key(_Bool value){
    return (int_get_hash_key(((int)value)));
}

unsigned int char_get_hash_key(char value){
    return value;
}

unsigned int short_get_hash_key(short int value){
    return value;
}

unsigned int int_get_hash_key(int value){
    return value;
}

unsigned int long_get_hash_key(long value){
    return value;
}

unsigned int size_t_get_hash_key(unsigned int value){
    return value;
}

unsigned int float_get_hash_key(float value){
    return (unsigned int)value;
}

unsigned int double_get_hash_key(double value){
    return (unsigned int)value;
}

unsigned int charp_get_hash_key(char* value){
int result;
char* p;
    if(    value==((void*)0)    ) {
        return 0;
    }
    result=0;
    p=value;
    while(    *p    ) {
        result+=(*p);
        p++;
    }
    return result;
}

unsigned int string_get_hash_key(char* value){
int result;
char* p;
    if(    value==((void*)0)    ) {
        return 0;
    }
    result=0;
    p=value;
    while(    *p    ) {
        result+=(*p);
        p++;
    }
    return result;
}

unsigned int voidp_get_hash_key(void* value){
    return (int_get_hash_key(((int)value)));
}

_Bool bool_clone(_Bool self){
    return self;
}

_Bool _Bool_clone(_Bool self){
    return self;
}

char char_clone(char self){
    return self;
}

short int short_clone(short self){
    return self;
}

int int_clone(int self){
    return self;
}

long  int long_clone(long self){
    return self;
}

unsigned int size_t_clone(unsigned int self){
    return self;
}

double double_clone(double self){
    return self;
}

float float_clone(float self){
    return self;
}

_Bool xisalpha(char c){
_Bool result;
    result=(c>=97&&c<=122)||(c>=65&&c<=90);
    return result;
}

_Bool xisblank(char c){
    return c==32||c==9;
}

_Bool xisdigit(char c){
    return (c>=48&&c<=57);
}

_Bool xisspace(char c){
    return c==32||c==9||c==10||c==13||c==28||c==11;
}

_Bool xisalnum(char c){
    return xisalpha(c)||xisdigit(c);
}

_Bool xisascii(char c){
_Bool result;
    result=(c>=32&&c<=126);
    return result;
}

_Bool xispunct(char c){
    return (c>=33&&c<=47)||(c>=58&&c<=64)||(c>=91&&c<=96)||(c>=123&&c<=126);
}

int string_length(char* str){
    if(    str==((void*)0)    ) {
        return 0;
    }
    return strlen(str);
}

int charp_length(char* str){
    if(    str==((void*)0)    ) {
        return 0;
    }
    return strlen(str);
}

char* charp_reverse(char* str){
void* __right_value0 = (void*)0;
char* __result_obj__93;
int len;
char* result;
int i;
char* __result_obj__94;
    if(    str==((void*)0)    ) {
        __result_obj__93 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__93 = come_decrement_ref_count(__result_obj__93, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__93;
    }
    len=strlen(str);
    __right_value0 = (void*)0;
    result=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(len+1)), "/usr/local/include/comelang.h", 9084, "char*"));
    for(    i=0    ;    i<len    ;    i++    ){
        result[i]=str[len-i-1];
    }
    result[len]=0;
    __result_obj__94 = (char*)come_increment_ref_count(result);
    (result = come_decrement_ref_count(result, (void*)0, (void*)0, 0, 1, (void*)0));
    (__result_obj__94 = come_decrement_ref_count(__result_obj__94, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__94;
}

char* string_operator_load_range_element(char* str, int head, int tail){
void* __right_value0 = (void*)0;
char* __result_obj__95;
int len;
void* __right_value1 = (void*)0;
char* __result_obj__96;
char* __result_obj__97;
char* __result_obj__98;
char* result;
char* __result_obj__99;
    if(    str==((void*)0)    ) {
        __result_obj__95 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__95 = come_decrement_ref_count(__result_obj__95, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__95;
    }
    len=strlen(str);
    if(    head<0    ) {
        head+=len;
    }
    if(    tail<0    ) {
        tail+=len+1;
    }
    if(    head>tail    ) {
        __right_value0 = (void*)0;
        __result_obj__96 = (char*)come_increment_ref_count(((char*)(__right_value1=charp_reverse(((char*)(__right_value0=charp_substring(str,tail,head)))))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__right_value1 = come_decrement_ref_count(__right_value1, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__96 = come_decrement_ref_count(__result_obj__96, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__96;
    }
    if(    head<0    ) {
        head=0;
    }
    if(    tail>=len    ) {
        tail=len;
    }
    if(    head==tail    ) {
        __right_value0 = (void*)0;
        __result_obj__97 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__97 = come_decrement_ref_count(__result_obj__97, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__97;
    }
    if(    tail-head+1<1    ) {
        __right_value0 = (void*)0;
        __result_obj__98 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__98 = come_decrement_ref_count(__result_obj__98, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__98;
    }
    __right_value0 = (void*)0;
    result=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(tail-head+1)), "/usr/local/include/comelang.h", 9130, "char*"));
    memcpy(result,str+head,tail-head);
    result[tail-head]=0;
    __result_obj__99 = (char*)come_increment_ref_count(result);
    (result = come_decrement_ref_count(result, (void*)0, (void*)0, 0, 1, (void*)0));
    (__result_obj__99 = come_decrement_ref_count(__result_obj__99, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__99;
}

char* charp_operator_load_range_element(char* str, int head, int tail){
void* __right_value0 = (void*)0;
char* __result_obj__100;
int len;
void* __right_value1 = (void*)0;
char* __result_obj__101;
char* __result_obj__102;
char* __result_obj__103;
char* result;
char* __result_obj__104;
    if(    str==((void*)0)    ) {
        __result_obj__100 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__100 = come_decrement_ref_count(__result_obj__100, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__100;
    }
    len=strlen(str);
    if(    head<0    ) {
        head+=len;
    }
    if(    tail<0    ) {
        tail+=len+1;
    }
    if(    head>tail    ) {
        __right_value0 = (void*)0;
        __result_obj__101 = (char*)come_increment_ref_count(((char*)(__right_value1=charp_reverse(((char*)(__right_value0=charp_substring(str,tail,head)))))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__right_value1 = come_decrement_ref_count(__right_value1, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__101 = come_decrement_ref_count(__result_obj__101, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__101;
    }
    if(    head<0    ) {
        head=0;
    }
    if(    tail>=len    ) {
        tail=len;
    }
    if(    head==tail    ) {
        __right_value0 = (void*)0;
        __result_obj__102 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__102 = come_decrement_ref_count(__result_obj__102, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__102;
    }
    if(    tail-head+1<1    ) {
        __right_value0 = (void*)0;
        __result_obj__103 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__103 = come_decrement_ref_count(__result_obj__103, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__103;
    }
    __right_value0 = (void*)0;
    result=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(tail-head+1)), "/usr/local/include/comelang.h", 9173, "char*"));
    memcpy(result,str+head,tail-head);
    result[tail-head]=0;
    __result_obj__104 = (char*)come_increment_ref_count(result);
    (result = come_decrement_ref_count(result, (void*)0, (void*)0, 0, 1, (void*)0));
    (__result_obj__104 = come_decrement_ref_count(__result_obj__104, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__104;
}

char* charp_substring(char* str, int head, int tail){
void* __right_value0 = (void*)0;
char* __result_obj__105;
int len;
void* __right_value1 = (void*)0;
char* __result_obj__106;
char* __result_obj__107;
char* __result_obj__108;
char* result;
char* __result_obj__109;
    if(    str==((void*)0)    ) {
        __result_obj__105 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__105 = come_decrement_ref_count(__result_obj__105, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__105;
    }
    len=strlen(str);
    if(    head<0    ) {
        head+=len;
    }
    if(    tail<0    ) {
        tail+=len+1;
    }
    if(    head>tail    ) {
        __right_value0 = (void*)0;
        __result_obj__106 = (char*)come_increment_ref_count(((char*)(__right_value1=charp_reverse(((char*)(__right_value0=charp_substring(str,tail,head)))))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__right_value1 = come_decrement_ref_count(__right_value1, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__106 = come_decrement_ref_count(__result_obj__106, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__106;
    }
    if(    head<0    ) {
        head=0;
    }
    if(    tail>=len    ) {
        tail=len;
    }
    if(    head==tail    ) {
        __right_value0 = (void*)0;
        __result_obj__107 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__107 = come_decrement_ref_count(__result_obj__107, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__107;
    }
    if(    tail-head+1<1    ) {
        __right_value0 = (void*)0;
        __result_obj__108 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__108 = come_decrement_ref_count(__result_obj__108, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__108;
    }
    __right_value0 = (void*)0;
    result=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(tail-head+1)), "/usr/local/include/comelang.h", 9216, "char*"));
    memcpy(result,str+head,tail-head);
    result[tail-head]=0;
    __result_obj__109 = (char*)come_increment_ref_count(result);
    (result = come_decrement_ref_count(result, (void*)0, (void*)0, 0, 1, (void*)0));
    (__result_obj__109 = come_decrement_ref_count(__result_obj__109, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__109;
}

char* xsprintf(char* msg, ...){
void* __right_value0 = (void*)0;
char* __result_obj__110;
va_list args;
char* result;
int len;
char* __result_obj__111;
char* result2;
char* __result_obj__112;
result = (void*)0;
    if(    msg==((void*)0)    ) {
        __result_obj__110 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__110 = come_decrement_ref_count(__result_obj__110, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__110;
    }
    __builtin_va_start(args,msg);
    len=vasprintf(&result,msg,args);
    __builtin_va_end(args);
    if(    len<0    ) {
        __right_value0 = (void*)0;
        __result_obj__111 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__111 = come_decrement_ref_count(__result_obj__111, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__111;
    }
    __right_value0 = (void*)0;
    result2=(char*)come_increment_ref_count(__builtin_string(result));
    free(result);
    __result_obj__112 = (char*)come_increment_ref_count(result2);
    (result2 = come_decrement_ref_count(result2, (void*)0, (void*)0, 0, 1, (void*)0));
    (__result_obj__112 = come_decrement_ref_count(__result_obj__112, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__112;
}

char* charp_delete(char* str, int head, int tail){
void* __right_value0 = (void*)0;
char* __result_obj__113;
int len;
char* __result_obj__114;
char* __result_obj__115;
char* result;
char* __result_obj__116;
    if(    str==((void*)0)    ) {
        __result_obj__113 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__113 = come_decrement_ref_count(__result_obj__113, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__113;
    }
    len=strlen(str);
    if(    strcmp(str,"")==0    ) {
        __right_value0 = (void*)0;
        __result_obj__114 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(str))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__114 = come_decrement_ref_count(__result_obj__114, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__114;
    }
    if(    head<0    ) {
        head+=len;
    }
    if(    tail<0    ) {
        tail+=len+1;
    }
    if(    head<0    ) {
        head=0;
    }
    if(    tail<0    ) {
        __right_value0 = (void*)0;
        __result_obj__115 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(str))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__115 = come_decrement_ref_count(__result_obj__115, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__115;
    }
    if(    tail>=len    ) {
        tail=len;
    }
    __right_value0 = (void*)0;
    result=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(len-(tail-head)+1)), "/usr/local/include/comelang.h", 9278, "char*"));
    memcpy(result,str,head);
    memcpy(result+head,str+tail,len-tail);
    result[len-(tail-head)]=0;
    __result_obj__116 = (char*)come_increment_ref_count(result);
    (result = come_decrement_ref_count(result, (void*)0, (void*)0, 0, 1, (void*)0));
    (__result_obj__116 = come_decrement_ref_count(__result_obj__116, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__116;
}

static struct list$1char$ph* list$1char$ph_initialize(struct list$1char$ph* self){
struct list$1char$ph* __result_obj__117;
    self->head=((void*)0);
    self->tail=((void*)0);
    self->len=0;
    __result_obj__117 = (struct list$1char$ph*)come_increment_ref_count(self);
    come_call_finalizer(list$1char$ph$p_finalize, self, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    come_call_finalizer(list$1char$ph$p_finalize, __result_obj__117, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__117;
}

static void list$1char$ph$p_finalize(struct list$1char$ph* self){
struct list_item$1char$ph* it;
struct list_item$1char$ph* prev_it;
    it=self->head;
    while(    it!=((void*)0)    ) {
        prev_it=it;
        it=it->next;
        come_call_finalizer(list_item$1char$ph$p_finalize, prev_it, (void*)0, (void*)0, 0, 0, 0, (void*)0);
    }
}

static void list_item$1char$ph$p_finalize(struct list_item$1char$ph* self){
    if(    self!=((void*)0)&&self->item!=((void*)0)    ) {
        (self->item = come_decrement_ref_count(self->item, (void*)0, (void*)0, 0, 0, (void*)0));
    }
}

static struct list$1char$ph* list$1char$ph_push_back(struct list$1char$ph* self, char* item){
void* __right_value0 = (void*)0;
struct list_item$1char$ph* litem;
char* __dec_obj17;
struct list_item$1char$ph* litem_22;
char* __dec_obj18;
struct list_item$1char$ph* litem_23;
char* __dec_obj19;
struct list$1char$ph* __result_obj__119;
    if(    self->len==0    ) {
        litem=(struct list_item$1char$ph*)come_increment_ref_count(((struct list_item$1char$ph*)(__right_value0=(struct list_item$1char$ph*)come_calloc_v2(1, sizeof(struct list_item$1char$ph)*(1), "/usr/local/include/comelang.h", 6239, "struct list_item$1char$ph*"))));
        litem->prev=((void*)0);
        litem->next=((void*)0);
        __dec_obj17=litem->item,
        litem->item=(char*)come_increment_ref_count(item);
        __dec_obj17 = come_decrement_ref_count(__dec_obj17, (void*)0, (void*)0, 0,0, (void*)0);
        self->tail=litem;
        self->head=litem;
    }
    else if(    self->len==1    ) {
        __right_value0 = (void*)0;
        litem_22=(struct list_item$1char$ph*)come_increment_ref_count(((struct list_item$1char$ph*)(__right_value0=(struct list_item$1char$ph*)come_calloc_v2(1, sizeof(struct list_item$1char$ph)*(1), "/usr/local/include/comelang.h", 6249, "struct list_item$1char$ph*"))));
        litem_22->prev=self->head;
        litem_22->next=((void*)0);
        __dec_obj18=litem_22->item,
        litem_22->item=(char*)come_increment_ref_count(item);
        __dec_obj18 = come_decrement_ref_count(__dec_obj18, (void*)0, (void*)0, 0,0, (void*)0);
        self->tail=litem_22;
        self->head->next=litem_22;
    }
    else {
        __right_value0 = (void*)0;
        litem_23=(struct list_item$1char$ph*)come_increment_ref_count(((struct list_item$1char$ph*)(__right_value0=(struct list_item$1char$ph*)come_calloc_v2(1, sizeof(struct list_item$1char$ph)*(1), "/usr/local/include/comelang.h", 6259, "struct list_item$1char$ph*"))));
        litem_23->prev=self->tail;
        litem_23->next=((void*)0);
        __dec_obj19=litem_23->item,
        litem_23->item=(char*)come_increment_ref_count(item);
        __dec_obj19 = come_decrement_ref_count(__dec_obj19, (void*)0, (void*)0, 0,0, (void*)0);
        self->tail->next=litem_23;
        self->tail=litem_23;
    }
    self->len++;
    __result_obj__119 = self;
    (item = come_decrement_ref_count(item, (void*)0, (void*)0, 0, 0, (void*)0));
    return __result_obj__119;
}

struct list$1char$ph* charp_split_char(char* self, char c){
void* __right_value0 = (void*)0;
void* __right_value1 = (void*)0;
struct list$1char$ph* __result_obj__118;
struct list$1char$ph* result;
struct buffer* str;
int i;
struct list$1char$ph* __result_obj__120;
    if(    self==((void*)0)    ) {
        __result_obj__118 = (struct list$1char$ph*)come_increment_ref_count(((struct list$1char$ph*)(__right_value1=list$1char$ph_initialize((struct list$1char$ph*)come_increment_ref_count((struct list$1char$ph*)come_calloc_v2(1, sizeof(struct list$1char$ph)*(1), "/usr/local/include/comelang.h", 9291, "struct list$1char$ph*"))))));
        come_call_finalizer(list$1char$ph$p_finalize, __right_value1, (void*)0, (void*)0, 0, 1, 0, (void*)0);
        come_call_finalizer(list$1char$ph$p_finalize, __result_obj__118, (void*)0, (void*)0, 0, 0, 1, (void*)0);
        return __result_obj__118;
    }
    __right_value0 = (void*)0;
    __right_value1 = (void*)0;
    result=(struct list$1char$ph*)come_increment_ref_count(list$1char$ph_initialize((struct list$1char$ph*)come_increment_ref_count((struct list$1char$ph*)come_calloc_v2(1, sizeof(struct list$1char$ph)*(1), "/usr/local/include/comelang.h", 9294, "struct list$1char$ph*"))));
    __right_value0 = (void*)0;
    __right_value1 = (void*)0;
    str=(struct buffer*)come_increment_ref_count(buffer_initialize((struct buffer*)come_increment_ref_count((struct buffer*)come_calloc_v2(1, sizeof(struct buffer)*(1), "/usr/local/include/comelang.h", 9296, "struct buffer*"))));
    for(    i=0    ;    i<charp_length(self)    ;    i++    ){
        if(        self[i]==c        ) {
            __right_value0 = (void*)0;
            list$1char$ph_push_back(result,(char*)come_increment_ref_count(__builtin_string(str->buf)));
            buffer_reset(str);
        }
        else {
            buffer_append_char(str,self[i]);
        }
    }
    if(    buffer_length(str)!=0    ) {
        __right_value0 = (void*)0;
        list$1char$ph_push_back(result,(char*)come_increment_ref_count(__builtin_string(str->buf)));
    }
    __result_obj__120 = (struct list$1char$ph*)come_increment_ref_count(result);
    come_call_finalizer(list$1char$ph$p_finalize, result, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    come_call_finalizer(buffer_finalize, str, (void*)0, (void*)0, 0, 0, 0, (void*)0);
    come_call_finalizer(list$1char$ph$p_finalize, __result_obj__120, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__120;
}

char* charp_xsprintf(char* self, char* msg, ...){
void* __right_value0 = (void*)0;
char* __result_obj__121;
    __result_obj__121 = (char*)come_increment_ref_count(((char*)(__right_value0=xsprintf(msg,self))));
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__121 = come_decrement_ref_count(__result_obj__121, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__121;
}

char* int_xsprintf(int self, char* msg, ...){
void* __right_value0 = (void*)0;
char* __result_obj__122;
    __result_obj__122 = (char*)come_increment_ref_count(((char*)(__right_value0=xsprintf(msg,self))));
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__122 = come_decrement_ref_count(__result_obj__122, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__122;
}

char* charp_printable(char* str){
int len;
void* __right_value0 = (void*)0;
char* result;
int n;
int i;
char c;
char* __result_obj__123;
    len=charp_length(str);
    result=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(len*2+1)), "/usr/local/include/comelang.h", 9328, "char*"));
    n=0;
    for(    i=0    ;    i<len    ;    i++    ){
        c=str[i];
        if(        (c>=0&&c<32)||c==127        ) {
            result[n++]=94;
            result[n++]=c+65-1;
        }
        else {
            result[n++]=c;
        }
    }
    result[n]=0;
    __result_obj__123 = (char*)come_increment_ref_count(result);
    (result = come_decrement_ref_count(result, (void*)0, (void*)0, 0, 1, (void*)0));
    (__result_obj__123 = come_decrement_ref_count(__result_obj__123, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__123;
}

char* charp_sub_plain(char* self, char* str, char* replace){
void* __right_value0 = (void*)0;
char* __result_obj__124;
void* __right_value1 = (void*)0;
struct buffer* result;
char* p;
char* p2;
char* __result_obj__125;
    if(    str==((void*)0)||replace==((void*)0)    ) {
        __result_obj__124 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(self))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__124 = come_decrement_ref_count(__result_obj__124, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__124;
    }
    __right_value0 = (void*)0;
    result=(struct buffer*)come_increment_ref_count(buffer_initialize((struct buffer*)come_increment_ref_count((struct buffer*)come_calloc_v2(1, sizeof(struct buffer)*(1), "/usr/local/include/comelang.h", 9356, "struct buffer*"))));
    p=self;
    while(    (_Bool)1    ) {
        p2=strstr(p,str);
        if(        p2==((void*)0)        ) {
            p2=p;
            while(            *p2            ) {
                p2++;
            }
            buffer_append(result,p,p2-p);
            break;
        }
        buffer_append(result,p,p2-p);
        buffer_append_str(result,replace);
        p=p2+strlen(str);
    }
    __right_value0 = (void*)0;
    __result_obj__125 = (char*)come_increment_ref_count(((char*)(__right_value0=buffer_to_string(result))));
    come_call_finalizer(buffer_finalize, result, (void*)0, (void*)0, 0, 0, 0, (void*)0);
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__125 = come_decrement_ref_count(__result_obj__125, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__125;
}

char* xbasename(char* path){
void* __right_value0 = (void*)0;
char* __result_obj__126;
char* p;
char* __result_obj__127;
char* __result_obj__128;
char* __result_obj__129;
    if(    path==((void*)0)    ) {
        __result_obj__126 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__126 = come_decrement_ref_count(__result_obj__126, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__126;
    }
    p=path+strlen(path);
    while(    p>=path    ) {
        if(        *p==47        ) {
            break;
        }
        else {
            p--;
        }
    }
    if(    p<path    ) {
        __right_value0 = (void*)0;
        __result_obj__127 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(path))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__127 = come_decrement_ref_count(__result_obj__127, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__127;
    }
    else {
        __right_value0 = (void*)0;
        __result_obj__128 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(p+1))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__128 = come_decrement_ref_count(__result_obj__128, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__128;
    }
    __right_value0 = (void*)0;
    __result_obj__129 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__129 = come_decrement_ref_count(__result_obj__129, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__129;
}

char* xnoextname(char* path){
void* __right_value0 = (void*)0;
char* __result_obj__130;
char* path2;
char* p;
char* __result_obj__131;
char* __result_obj__132;
char* __result_obj__133;
    if(    path==((void*)0)    ) {
        __result_obj__130 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__130 = come_decrement_ref_count(__result_obj__130, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__130;
    }
    __right_value0 = (void*)0;
    path2=(char*)come_increment_ref_count(xbasename(path));
    p=path2+strlen(path2);
    while(    p>=path2    ) {
        if(        *p==46        ) {
            break;
        }
        else {
            p--;
        }
    }
    if(    p<path2    ) {
        __right_value0 = (void*)0;
        __result_obj__131 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(path2))));
        (path2 = come_decrement_ref_count(path2, (void*)0, (void*)0, 0, 0, (void*)0));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__131 = come_decrement_ref_count(__result_obj__131, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__131;
    }
    else {
        __right_value0 = (void*)0;
        __result_obj__132 = (char*)come_increment_ref_count(((char*)(__right_value0=charp_substring(path2,0,p-path2))));
        (path2 = come_decrement_ref_count(path2, (void*)0, (void*)0, 0, 0, (void*)0));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__132 = come_decrement_ref_count(__result_obj__132, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__132;
    }
    __right_value0 = (void*)0;
    __result_obj__133 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
    (path2 = come_decrement_ref_count(path2, (void*)0, (void*)0, 0, 0, (void*)0));
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__133 = come_decrement_ref_count(__result_obj__133, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__133;
}

char* xextname(char* path){
void* __right_value0 = (void*)0;
char* __result_obj__134;
char* p;
char* __result_obj__135;
char* __result_obj__136;
char* __result_obj__137;
    if(    path==((void*)0)    ) {
        __result_obj__134 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__134 = come_decrement_ref_count(__result_obj__134, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__134;
    }
    p=path+strlen(path);
    while(    p>=path    ) {
        if(        *p==46        ) {
            break;
        }
        else {
            p--;
        }
    }
    if(    p<path    ) {
        __right_value0 = (void*)0;
        __result_obj__135 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(path))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__135 = come_decrement_ref_count(__result_obj__135, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__135;
    }
    else {
        __right_value0 = (void*)0;
        __result_obj__136 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(p+1))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__136 = come_decrement_ref_count(__result_obj__136, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__136;
    }
    __right_value0 = (void*)0;
    __result_obj__137 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__137 = come_decrement_ref_count(__result_obj__137, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__137;
}

char* bool_to_string(_Bool self){
void* __right_value0 = (void*)0;
char* __result_obj__138;
char* __result_obj__139;
    if(    self    ) {
        __result_obj__138 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string("true"))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__138 = come_decrement_ref_count(__result_obj__138, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__138;
    }
    else {
        __right_value0 = (void*)0;
        __result_obj__139 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string("false"))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__139 = come_decrement_ref_count(__result_obj__139, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__139;
    }
}

char* _Bool_to_string(_Bool self){
void* __right_value0 = (void*)0;
char* __result_obj__140;
char* __result_obj__141;
    if(    self    ) {
        __result_obj__140 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string("true"))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__140 = come_decrement_ref_count(__result_obj__140, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__140;
    }
    else {
        __right_value0 = (void*)0;
        __result_obj__141 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string("false"))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__141 = come_decrement_ref_count(__result_obj__141, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__141;
    }
}

char* char_to_string(char self){
void* __right_value0 = (void*)0;
char* __result_obj__142;
    __result_obj__142 = (char*)come_increment_ref_count(((char*)(__right_value0=xsprintf("%c",self))));
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__142 = come_decrement_ref_count(__result_obj__142, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__142;
}

char* short_to_string(short self){
void* __right_value0 = (void*)0;
char* __result_obj__143;
    __result_obj__143 = (char*)come_increment_ref_count(((char*)(__right_value0=xsprintf("%d",self))));
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__143 = come_decrement_ref_count(__result_obj__143, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__143;
}

char* int_to_string(int self){
void* __right_value0 = (void*)0;
char* __result_obj__144;
    __result_obj__144 = (char*)come_increment_ref_count(((char*)(__right_value0=xsprintf("%d",self))));
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__144 = come_decrement_ref_count(__result_obj__144, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__144;
}

char* long_to_string(long self){
void* __right_value0 = (void*)0;
char* __result_obj__145;
    __result_obj__145 = (char*)come_increment_ref_count(((char*)(__right_value0=xsprintf("%ld",self))));
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__145 = come_decrement_ref_count(__result_obj__145, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__145;
}

char* size_t_to_string(unsigned int self){
void* __right_value0 = (void*)0;
char* __result_obj__146;
    __result_obj__146 = (char*)come_increment_ref_count(((char*)(__right_value0=xsprintf("%ld",self))));
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__146 = come_decrement_ref_count(__result_obj__146, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__146;
}

char* float_to_string(float self){
void* __right_value0 = (void*)0;
char* __result_obj__147;
    __result_obj__147 = (char*)come_increment_ref_count(((char*)(__right_value0=xsprintf("%f",self))));
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__147 = come_decrement_ref_count(__result_obj__147, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__147;
}

char* double_to_string(double self){
void* __right_value0 = (void*)0;
char* __result_obj__148;
    __result_obj__148 = (char*)come_increment_ref_count(((char*)(__right_value0=xsprintf("%lf",self))));
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__148 = come_decrement_ref_count(__result_obj__148, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__148;
}

char* string_to_string(char* self){
void* __right_value0 = (void*)0;
char* __result_obj__149;
char* __result_obj__150;
    if(    self==((void*)0)    ) {
        __result_obj__149 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__149 = come_decrement_ref_count(__result_obj__149, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__149;
    }
    __right_value0 = (void*)0;
    __result_obj__150 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(self))));
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__150 = come_decrement_ref_count(__result_obj__150, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__150;
}

char* charp_to_string(char* self){
void* __right_value0 = (void*)0;
char* __result_obj__151;
char* __result_obj__152;
    if(    self==((void*)0)    ) {
        __result_obj__151 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__151 = come_decrement_ref_count(__result_obj__151, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__151;
    }
    __right_value0 = (void*)0;
    __result_obj__152 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(self))));
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__152 = come_decrement_ref_count(__result_obj__152, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__152;
}

int bool_compare(_Bool left, _Bool right){
    if(    !left&&right    ) {
        return -1;
    }
    else if(    left&&right    ) {
        return 0;
    }
    else if(    !left&&!right    ) {
        return 0;
    }
    else {
        return 1;
    }
    return 0;
}

int _Bool_compare(_Bool left, _Bool right){
    if(    !left&&right    ) {
        return -1;
    }
    else if(    left&&right    ) {
        return 0;
    }
    else if(    !left&&!right    ) {
        return 0;
    }
    else {
        return 1;
    }
    return 0;
}

int char_compare(char left, char right){
    if(    left<right    ) {
        return -1;
    }
    else if(    left>right    ) {
        return 1;
    }
    else {
        return 0;
    }
    return 0;
}

int short_compare(short left, short right){
    if(    left<right    ) {
        return -1;
    }
    else if(    left>right    ) {
        return 1;
    }
    else {
        return 0;
    }
    return 0;
}

int int_compare(int left, int right){
    if(    left<right    ) {
        return -1;
    }
    else if(    left>right    ) {
        return 1;
    }
    else {
        return 0;
    }
    return 0;
}

int long_compare(long left, long right){
    if(    left<right    ) {
        return -1;
    }
    else if(    left>right    ) {
        return 1;
    }
    else {
        return 0;
    }
    return 0;
}

int size_t_compare(unsigned int left, unsigned int right){
    if(    left<right    ) {
        return -1;
    }
    else if(    left>right    ) {
        return 1;
    }
    else {
        return 0;
    }
    return 0;
}

int float_compare(float left, float right){
    if(    left<right    ) {
        return -1;
    }
    else if(    left>right    ) {
        return 1;
    }
    else {
        return 0;
    }
    return 0;
}

int double_compare(double left, double right){
    if(    left<right    ) {
        return -1;
    }
    else if(    left>right    ) {
        return 1;
    }
    else {
        return 0;
    }
    return 0;
}

int string_compare(char* left, char* right){
    if(    left==((void*)0)&&right==((void*)0)    ) {
        return 0;
    }
    else if(    left==((void*)0)    ) {
        return -1;
    }
    else if(    right==((void*)0)    ) {
        return 1;
    }
    return strcmp(left,right);
}

int charp_compare(char* left, char* right){
    if(    left==((void*)0)&&right==((void*)0)    ) {
        return 0;
    }
    else if(    left==((void*)0)    ) {
        return -1;
    }
    else if(    right==((void*)0)    ) {
        return 1;
    }
    return strcmp(left,right);
}

char* charp_puts(char* self){
void* __right_value0 = (void*)0;
char* __result_obj__153;
char* __result_obj__154;
    if(    self==((void*)0)    ) {
        __result_obj__153 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__153 = come_decrement_ref_count(__result_obj__153, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__153;
    }
    puts(self);
    __right_value0 = (void*)0;
    __result_obj__154 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(self))));
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__154 = come_decrement_ref_count(__result_obj__154, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__154;
}

char* charp_print(char* self){
void* __right_value0 = (void*)0;
char* __result_obj__155;
char* __result_obj__156;
    if(    self==((void*)0)    ) {
        __result_obj__155 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__155 = come_decrement_ref_count(__result_obj__155, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__155;
    }
    printf("%s",self);
    __right_value0 = (void*)0;
    __result_obj__156 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(self))));
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__156 = come_decrement_ref_count(__result_obj__156, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__156;
}

char* charp_printf(char* self, ...){
void* __right_value0 = (void*)0;
char* __result_obj__157;
char* msg2;
va_list args;
char* __result_obj__158;
msg2 = (void*)0;
    if(    self==((void*)0)    ) {
        __result_obj__157 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__157 = come_decrement_ref_count(__result_obj__157, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__157;
    }
    __builtin_va_start(args,self);
    vasprintf(&msg2,self,args);
    __builtin_va_end(args);
    printf("%s",msg2);
    free(msg2);
    __right_value0 = (void*)0;
    __result_obj__158 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(self))));
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__158 = come_decrement_ref_count(__result_obj__158, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__158;
}

int int_printf(int self, char* msg){
    printf(msg,self);
    return self;
}

void int_times(int self, void* parent, void (*block)(void*,int)){
int i;
    for(    i=0    ;    i<self    ;    i++    ){
        block(parent,i);
    }
}

static void match_context_finalize(struct anonymous_typeX18* self){
}

int re_matchp(struct re_program* pattern, const char* text, int* matchlength, struct re_capture* captures, int max_captures){
struct re_program* program;
struct regex_t* start;
struct anonymous_typeX18 ctx;
int __result_obj__159;
int __result_obj__160;
int __result_obj__161;
int __result_obj__162;
int __result_obj__163;
memset(&ctx, 0, sizeof(struct anonymous_typeX18));
    *matchlength=0;
    if(    pattern==0    ) {
        return -1;
    }
    program=(struct re_program*)pattern;
    start=program->start;
    if(    start==0    ) {
        return -1;
    }
    ctx.base=text;
    ctx.captures=(((captures!=0&&max_captures>0))?(captures):(0));
    ctx.capture_capacity=(((captures!=0&&max_captures>0))?(max_captures):(0));
    if(    ctx.capture_capacity>64    ) {
        ctx.capture_capacity=64;
    }
    ctx.total_groups=program->group_count;
    if(    ctx.captures!=0    ) {
        clear_captures(&ctx);
    }
    if(    start->type==(2)    ) {
        const char* end=matchpattern(start->next,text,&ctx);
        if(        end!=0        ) {
            *matchlength=(int)(end-text);
            if(            ctx.captures!=0            ) {
            }
            __result_obj__159 = 0;
            come_call_finalizer(match_context_finalize, (&ctx), (void*)0, (void*)0, 1, 0, 0, (void*)0);
            return __result_obj__159;
        }
        __result_obj__160 = -1;
        come_call_finalizer(match_context_finalize, (&ctx), (void*)0, (void*)0, 1, 0, 0, (void*)0);
        return __result_obj__160;
    }
    else {
        const char* cursor=text;
        while(        1        ) {
            if(            ctx.captures!=0            ) {
                clear_captures(&ctx);
            }
            const char* end_24=matchpattern(start,cursor,&ctx);
            if(            end_24!=0            ) {
                if(                *cursor==0&&cursor!=text                ) {
                    __result_obj__161 = -1;
                    come_call_finalizer(match_context_finalize, (&ctx), (void*)0, (void*)0, 1, 0, 0, (void*)0);
                    return __result_obj__161;
                }
                *matchlength=(int)(end_24-cursor);
                __result_obj__162 = (int)(cursor-text);
                come_call_finalizer(match_context_finalize, (&ctx), (void*)0, (void*)0, 1, 0, 0, (void*)0);
                return __result_obj__162;
            }
            if(            *cursor==0            ) {
                break;
            }
            cursor+=1;
        }
    }
    __result_obj__163 = -1;
    come_call_finalizer(match_context_finalize, (&ctx), (void*)0, (void*)0, 1, 0, 0, (void*)0);
    return __result_obj__163;
}

int re_match(const char* pattern, const char* text, int* matchlength){
    return re_matchp(re_compile(pattern),text,matchlength,(struct re_capture*)0,0);
}

static void regex_program_t_finalize(struct re_program* self){
}

static void compiler_state_finalize(struct anonymous_typeX17* self){
}

struct re_program* re_compile(const char* pattern){
static struct re_program program;
struct anonymous_typeX17 state;
int pos;
struct regex_t* head;
struct re_program* __result_obj__164;
struct re_program* __result_obj__165;
memset(&program, 0, sizeof(struct re_program));
memset(&state, 0, sizeof(struct anonymous_typeX17));
    static struct regex_t re_compiled[64];
    memset(&re_compiled, 0, sizeof(struct regex_t)    *(64)    );
    static unsigned char ccl_buf[40];
    memset(&ccl_buf, 0, sizeof(unsigned char)    *(40)    );
    state.pool=re_compiled;
    state.pool_capacity=64;
    state.pool_size=0;
    state.ccl_buf=ccl_buf;
    state.ccl_capacity=40;
    state.ccl_idx=1;
    state.group_count=0;
    if(    state.ccl_capacity>0    ) {
        state.ccl_buf[0]=0;
    }
    pos=0;
    head=compile_sequence(&state,pattern,&pos,0);
    if(    (head==0)||(pattern[pos]!=0)    ) {
        __result_obj__164 = ((void*)0);
        come_call_finalizer(regex_program_t_finalize, (&program), (void*)0, (void*)0, 1, 0, 0, (void*)0);
        come_call_finalizer(compiler_state_finalize, (&state), (void*)0, (void*)0, 1, 0, 0, (void*)0);
        return __result_obj__164;
    }
    program.start=head;
    program.group_count=state.group_count;
    __result_obj__165 = (struct re_program*)&program;
    come_call_finalizer(regex_program_t_finalize, (&program), (void*)0, (void*)0, 1, 0, 0, (void*)0);
    come_call_finalizer(compiler_state_finalize, (&state), (void*)0, (void*)0, 1, 0, 0, (void*)0);
    return __result_obj__165;
}

void re_print(struct re_program* pattern){
struct re_program* program;
    if(    pattern==0    ) {
        return;
    }
    program=(struct re_program*)pattern;
    if(    program->start==0    ) {
        return;
    }
    re_print_internal(program->start,0);
}

void clear_captures(struct anonymous_typeX18* ctx){
int i;
    if(    (ctx->captures==0)||(ctx->capture_capacity<=0)    ) {
        return;
    }
    for(    i=0    ;    i<ctx->capture_capacity    ;    ++i    ){
        ctx->captures[i].start=-1;
        ctx->captures[i].length=0;
    }
}

void snapshot_captures(const struct anonymous_typeX18* ctx, struct re_capture* buffer_){
    if(    (ctx->captures==0)||(ctx->capture_capacity<=0)    ) {
        return;
    }
    memcpy(buffer_,ctx->captures,sizeof(struct re_capture)*ctx->capture_capacity);
}

void restore_captures(struct anonymous_typeX18* ctx, const struct re_capture* buffer_){
    if(    (ctx->captures==0)||(ctx->capture_capacity<=0)    ) {
        return;
    }
    memcpy(ctx->captures,buffer_,sizeof(struct re_capture)*ctx->capture_capacity);
}

struct regex_t* new_token(struct anonymous_typeX17* st){
struct regex_t* __result_obj__166;
struct regex_t* token;
struct regex_t* __result_obj__167;
    if(    st->pool_size>=st->pool_capacity    ) {
        __result_obj__166 = ((void*)0);
        return __result_obj__166;
    }
    token=&st->pool[st->pool_size++];
    token->type=(0);
    token->u.ccl=0;
    token->next=0;
    token->u.group.first=0;
    token->u.group.id=0;
    __result_obj__167 = token;
    return __result_obj__167;
}

int append_token(struct regex_t** head, struct regex_t** tail, struct regex_t* token){
    if(    token==0    ) {
        return 0;
    }
    if(    *head==0    ) {
        *head=token;
    }
    else {
        (*tail)->next=token;
    }
    *tail=token;
    return 1;
}

struct regex_t* compile_sequence(struct anonymous_typeX17* st, const char* pattern, int* pos, int in_group){
struct regex_t* head;
struct regex_t* tail;
char c;
struct regex_t* token;
struct regex_t* __result_obj__168;
struct regex_t* __result_obj__169;
struct regex_t* __result_obj__170;
struct regex_t* __result_obj__171;
struct regex_t* __result_obj__172;
struct regex_t* __result_obj__173;
struct regex_t* __result_obj__174;
struct regex_t* __result_obj__175;
int buf_begin;
int negated;
struct regex_t* __result_obj__176;
struct regex_t* __result_obj__177;
struct regex_t* __result_obj__178;
struct regex_t* __result_obj__179;
struct regex_t* __result_obj__180;
struct regex_t* __result_obj__181;
struct regex_t* __result_obj__182;
struct regex_t* __result_obj__183;
struct regex_t* inner;
struct regex_t* __result_obj__184;
struct regex_t* __result_obj__185;
struct regex_t* __result_obj__186;
struct regex_t* __result_obj__187;
struct regex_t* __result_obj__188;
struct regex_t* __result_obj__189;
struct regex_t* sentinel;
struct regex_t* __result_obj__190;
struct regex_t* __result_obj__191;
    head=(struct regex_t*)0;
    tail=(struct regex_t*)0;
    while(    pattern[*pos]!=0    ) {
        c=pattern[*pos];
        if(        in_group&&(c==41)        ) {
            break;
        }
        token=(struct regex_t*)0;
        switch (        c) {
            case 94:
            {
                token=new_token(st);
                if(                token==0                ) {
                    __result_obj__168 = ((void*)0);
                    return __result_obj__168;
                }
                token->type=(2);
                (*pos)++;
            }
            break;
            case 36:
            {
                token=new_token(st);
                if(                token==0                ) {
                    __result_obj__169 = ((void*)0);
                    return __result_obj__169;
                }
                token->type=(3);
                (*pos)++;
            }
            break;
            case 46:
            {
                token=new_token(st);
                if(                token==0                ) {
                    __result_obj__170 = ((void*)0);
                    return __result_obj__170;
                }
                token->type=(1);
                (*pos)++;
            }
            break;
            case 42:
            {
                token=new_token(st);
                if(                token==0                ) {
                    __result_obj__171 = ((void*)0);
                    return __result_obj__171;
                }
                token->type=(5);
                (*pos)++;
            }
            break;
            case 43:
            {
                token=new_token(st);
                if(                token==0                ) {
                    __result_obj__172 = ((void*)0);
                    return __result_obj__172;
                }
                token->type=(6);
                (*pos)++;
            }
            break;
            case 63:
            {
                token=new_token(st);
                if(                token==0                ) {
                    __result_obj__173 = ((void*)0);
                    return __result_obj__173;
                }
                token->type=(4);
                (*pos)++;
            }
            break;
            case 92:
            {
                (*pos)++;
                if(                pattern[*pos]==0                ) {
                    __result_obj__174 = ((void*)0);
                    return __result_obj__174;
                }
                token=new_token(st);
                if(                token==0                ) {
                    __result_obj__175 = ((void*)0);
                    return __result_obj__175;
                }
                switch (                pattern[*pos]) {
                    case 100:
                    token->type=(10);
                    break;
                    case 68:
                    token->type=(11);
                    break;
                    case 119:
                    token->type=(12);
                    break;
                    case 87:
                    token->type=(13);
                    break;
                    case 115:
                    token->type=(14);
                    break;
                    case 83:
                    token->type=(15);
                    break;
                    default:
                    {
                        token->type=(7);
                        token->u.ch=(unsigned char)pattern[*pos];
                    }
                    break;
                }
                (*pos)++;
            }
            break;
            case 91:
            {
                buf_begin=st->ccl_idx;
                negated=0;
                (*pos)++;
                if(                pattern[*pos]==94                ) {
                    negated=1;
                    (*pos)++;
                    if(                    pattern[*pos]==0                    ) {
                        __result_obj__176 = ((void*)0);
                        return __result_obj__176;
                    }
                }
                if(                pattern[*pos]==0                ) {
                    __result_obj__177 = ((void*)0);
                    return __result_obj__177;
                }
                while(                (pattern[*pos]!=0)&&(pattern[*pos]!=93)                ) {
                    if(                    pattern[*pos]==92                    ) {
                        if(                        st->ccl_idx>=(st->ccl_capacity-1)                        ) {
                            __result_obj__178 = ((void*)0);
                            return __result_obj__178;
                        }
                        st->ccl_buf[st->ccl_idx++]=92;
                        (*pos)++;
                        if(                        pattern[*pos]==0                        ) {
                            __result_obj__179 = ((void*)0);
                            return __result_obj__179;
                        }
                    }
                    if(                    st->ccl_idx>=st->ccl_capacity                    ) {
                        __result_obj__180 = ((void*)0);
                        return __result_obj__180;
                    }
                    st->ccl_buf[st->ccl_idx++]=(unsigned char)pattern[*pos];
                    (*pos)++;
                }
                if(                pattern[*pos]!=93                ) {
                    __result_obj__181 = ((void*)0);
                    return __result_obj__181;
                }
                if(                st->ccl_idx>=st->ccl_capacity                ) {
                    __result_obj__182 = ((void*)0);
                    return __result_obj__182;
                }
                st->ccl_buf[st->ccl_idx++]=0;
                token=new_token(st);
                if(                token==0                ) {
                    __result_obj__183 = ((void*)0);
                    return __result_obj__183;
                }
                token->type=((negated)?((9)):((8)));
                token->u.ccl=&st->ccl_buf[buf_begin];
                (*pos)++;
            }
            break;
            case 40:
            {
                (*pos)++;
                inner=compile_sequence(st,pattern,pos,1);
                if(                inner==0                ) {
                    __result_obj__184 = ((void*)0);
                    return __result_obj__184;
                }
                if(                pattern[*pos]!=41                ) {
                    __result_obj__185 = ((void*)0);
                    return __result_obj__185;
                }
                token=new_token(st);
                if(                token==0                ) {
                    __result_obj__186 = ((void*)0);
                    return __result_obj__186;
                }
                token->type=(16);
                token->u.group.first=inner;
                token->u.group.id=++st->group_count;
                (*pos)++;
            }
            break;
            case 41:
            {
                token=new_token(st);
                if(                token==0                ) {
                    __result_obj__187 = ((void*)0);
                    return __result_obj__187;
                }
                token->type=(7);
                token->u.ch=(unsigned char)c;
                (*pos)++;
            }
            break;
            default:
            {
                token=new_token(st);
                if(                token==0                ) {
                    __result_obj__188 = ((void*)0);
                    return __result_obj__188;
                }
                token->type=(7);
                token->u.ch=(unsigned char)c;
                (*pos)++;
            }
            break;
        }
        if(        !append_token(&head,&tail,token)        ) {
            __result_obj__189 = ((void*)0);
            return __result_obj__189;
        }
    }
    sentinel=new_token(st);
    if(    sentinel==0    ) {
        __result_obj__190 = ((void*)0);
        return __result_obj__190;
    }
    sentinel->type=(0);
    sentinel->next=0;
    if(    head==0    ) {
        head=sentinel;
    }
    else {
        tail->next=sentinel;
    }
    __result_obj__191 = head;
    return __result_obj__191;
}

const char* matchpattern(struct regex_t* pattern, const char* text, struct anonymous_typeX18* ctx){
const char* __result_obj__192;
struct regex_t* current;
struct regex_t* next;
const char* __result_obj__193;
const char* __result_obj__194;
const char* __result_obj__195;
const char* __result_obj__196;
const char* __result_obj__197;
const char* __result_obj__198;
const char* __result_obj__199;
const char* __result_obj__200;
const char* __result_obj__201;
    if(    (pattern==0)||(pattern->type==(0))    ) {
        __result_obj__192 = text;
        return __result_obj__192;
    }
    struct re_capture snapshot[64];
    memset(&snapshot, 0, sizeof(struct re_capture)    *(64)    );
    snapshot_captures(ctx,snapshot);
    current=pattern;
    const char* cursor=text;
    while(    current!=0&&current->type!=(0)    ) {
        next=current->next;
        if(        (next!=0)&&(next->type==(4))        ) {
            const char* result=matchquestion(current,next->next,cursor,ctx);
            if(            result!=0            ) {
                __result_obj__193 = result;
                return __result_obj__193;
            }
            restore_captures(ctx,snapshot);
            __result_obj__194 = ((void*)0);
            return __result_obj__194;
        }
        else if(        (next!=0)&&(next->type==(5))        ) {
            const char* result_25=matchstar(current,next->next,cursor,ctx);
            if(            result_25!=0            ) {
                __result_obj__195 = result_25;
                return __result_obj__195;
            }
            restore_captures(ctx,snapshot);
            __result_obj__196 = ((void*)0);
            return __result_obj__196;
        }
        else if(        (next!=0)&&(next->type==(6))        ) {
            const char* result_26=matchplus(current,next->next,cursor,ctx);
            if(            result_26!=0            ) {
                __result_obj__197 = result_26;
                return __result_obj__197;
            }
            restore_captures(ctx,snapshot);
            __result_obj__198 = ((void*)0);
            return __result_obj__198;
        }
        else if(        current->type==(3)        ) {
            if(            *cursor!=0            ) {
                restore_captures(ctx,snapshot);
                __result_obj__199 = ((void*)0);
                return __result_obj__199;
            }
            current=current->next;
        }
        else {
            const char* after=matchtoken(current,cursor,ctx);
            if(            after==0            ) {
                restore_captures(ctx,snapshot);
                __result_obj__200 = ((void*)0);
                return __result_obj__200;
            }
            cursor=after;
            current=current->next;
        }
    }
    __result_obj__201 = cursor;
    return __result_obj__201;
}

const char* matchstar(struct regex_t* token, struct regex_t* rest, const char* text, struct anonymous_typeX18* ctx){
const char* __result_obj__202;
const char* __result_obj__203;
    struct re_capture snapshot_entry[64];
    memset(&snapshot_entry, 0, sizeof(struct re_capture)    *(64)    );
    snapshot_captures(ctx,snapshot_entry);
    const char* consume=matchtoken(token,text,ctx);
    while(    (consume!=0)&&(consume!=text)    ) {
        struct re_capture snapshot_after_token[64];
        memset(&snapshot_after_token, 0, sizeof(struct re_capture)        *(64)        );
        snapshot_captures(ctx,snapshot_after_token);
        const char* recursive=matchstar(token,rest,consume,ctx);
        if(        recursive!=0        ) {
            __result_obj__202 = recursive;
            return __result_obj__202;
        }
        restore_captures(ctx,snapshot_after_token);
        consume=matchtoken(token,consume,ctx);
    }
    restore_captures(ctx,snapshot_entry);
    __result_obj__203 = matchpattern(rest,text,ctx);
    return __result_obj__203;
}

const char* matchplus(struct regex_t* token, struct regex_t* rest, const char* text, struct anonymous_typeX18* ctx){
const char* __result_obj__204;
const char* __result_obj__205;
const char* __result_obj__206;
    struct re_capture snapshot_entry[64];
    memset(&snapshot_entry, 0, sizeof(struct re_capture)    *(64)    );
    snapshot_captures(ctx,snapshot_entry);
    const char* first=matchtoken(token,text,ctx);
    if(    (first==0)||(first==text)    ) {
        restore_captures(ctx,snapshot_entry);
        __result_obj__204 = ((void*)0);
        return __result_obj__204;
    }
    const char* result=matchstar(token,rest,first,ctx);
    if(    result!=0    ) {
        __result_obj__205 = result;
        return __result_obj__205;
    }
    restore_captures(ctx,snapshot_entry);
    __result_obj__206 = ((void*)0);
    return __result_obj__206;
}

const char* matchquestion(struct regex_t* token, struct regex_t* rest, const char* text, struct anonymous_typeX18* ctx){
const char* __result_obj__207;
const char* __result_obj__208;
const char* __result_obj__209;
const char* __result_obj__210;
    struct re_capture snapshot_entry[64];
    memset(&snapshot_entry, 0, sizeof(struct re_capture)    *(64)    );
    snapshot_captures(ctx,snapshot_entry);
    const char* skipped=matchpattern(rest,text,ctx);
    if(    skipped!=0    ) {
        __result_obj__207 = skipped;
        return __result_obj__207;
    }
    restore_captures(ctx,snapshot_entry);
    const char* consumed=matchtoken(token,text,ctx);
    if(    (consumed==0)||(consumed==text)    ) {
        restore_captures(ctx,snapshot_entry);
        __result_obj__208 = ((void*)0);
        return __result_obj__208;
    }
    const char* with=matchpattern(rest,consumed,ctx);
    if(    with!=0    ) {
        __result_obj__209 = with;
        return __result_obj__209;
    }
    restore_captures(ctx,snapshot_entry);
    __result_obj__210 = ((void*)0);
    return __result_obj__210;
}

const char* matchtoken(struct regex_t* token, const char* text, struct anonymous_typeX18* ctx){
const char* __result_obj__211;
const char* __result_obj__212;
const char* __result_obj__213;
const char* __result_obj__214;
const char* __result_obj__215;
const char* __result_obj__216;
const char* __result_obj__217;
const char* __result_obj__218;
const char* __result_obj__219;
const char* __result_obj__220;
const char* __result_obj__221;
int idx;
const char* __result_obj__222;
const char* __result_obj__223;
const char* __result_obj__224;
const char* __result_obj__225;
    switch (    token->type) {
        case (1):
        __result_obj__211 = (((*text!=0&&matchdot(*text)))?(text+1):(0));
        return __result_obj__211;
        case (7):
        __result_obj__212 = (((*text!=0&&token->u.ch==(unsigned char)*text))?(text+1):(0));
        return __result_obj__212;
        case (8):
        __result_obj__213 = (((*text!=0&&matchcharclass(*text,(const char*)token->u.ccl)))?(text+1):(0));
        return __result_obj__213;
        case (9):
        __result_obj__214 = (((*text!=0&&!matchcharclass(*text,(const char*)token->u.ccl)))?(text+1):(0));
        return __result_obj__214;
        case (10):
        __result_obj__215 = (((*text!=0&&matchdigit(*text)))?(text+1):(0));
        return __result_obj__215;
        case (11):
        __result_obj__216 = (((*text!=0&&!matchdigit(*text)))?(text+1):(0));
        return __result_obj__216;
        case (12):
        __result_obj__217 = (((*text!=0&&matchalphanum(*text)))?(text+1):(0));
        return __result_obj__217;
        case (13):
        __result_obj__218 = (((*text!=0&&!matchalphanum(*text)))?(text+1):(0));
        return __result_obj__218;
        case (14):
        __result_obj__219 = (((*text!=0&&matchwhitespace(*text)))?(text+1):(0));
        return __result_obj__219;
        case (15):
        __result_obj__220 = (((*text!=0&&!matchwhitespace(*text)))?(text+1):(0));
        return __result_obj__220;
        case (16):
        {
            struct re_capture snapshot[64];
            memset(&snapshot, 0, sizeof(struct re_capture)            *(64)            );
            snapshot_captures(ctx,snapshot);
            const char* start=text;
            const char* end=matchpattern(token->u.group.first,text,ctx);
            if(            end==0            ) {
                restore_captures(ctx,snapshot);
                __result_obj__221 = ((void*)0);
                return __result_obj__221;
            }
            if(            token->u.group.id>0&&ctx->captures!=0            ) {
                idx=token->u.group.id-1;
                if(                idx<ctx->capture_capacity                ) {
                    ctx->captures[idx].start=(int)(start-ctx->base);
                    ctx->captures[idx].length=(int)(end-start);
                }
            }
            __result_obj__222 = end;
            return __result_obj__222;
        }
        case (2):
        __result_obj__223 = (((text==ctx->base))?(text):(0));
        return __result_obj__223;
        case (3):
        __result_obj__224 = (((*text==0))?(text):(0));
        return __result_obj__224;
        default:
        break;
    }
    __result_obj__225 = (const char*)0;
    return __result_obj__225;
}

int matchdigit(char c){
    return xisdigit((unsigned char)c);
}

int matchalpha(char c){
    return xisalpha((unsigned char)c);
}

int matchwhitespace(char c){
    return xisspace((unsigned char)c);
}

int matchalphanum(char c){
    return ((c==95)||matchalpha(c)||matchdigit(c));
}

int matchrange(char c, const char* str){
    return ((c!=45)&&(str[0]!=0)&&(str[0]!=45)&&(str[1]==45)&&(str[2]!=0)&&((c>=str[0])&&(c<=str[2])));
}

int matchdot(char c){
    return c!=10&&c!=13;
}

int ismetachar(char c){
    return ((c==115)||(c==83)||(c==119)||(c==87)||(c==100)||(c==68));
}

int matchmetachar(char c, const char* str){
    switch (    str[0]) {
        case 100:
        return matchdigit(c);
        case 68:
        return !matchdigit(c);
        case 119:
        return matchalphanum(c);
        case 87:
        return !matchalphanum(c);
        case 115:
        return matchwhitespace(c);
        case 83:
        return !matchwhitespace(c);
        default:
        return (c==str[0]);
    }
}

int matchcharclass(char c, const char* str){
    do {
        if(        matchrange(c,str)        ) {
            return 1;
        }
        else if(        str[0]==92        ) {
            str+=1;
            if(            matchmetachar(c,str)            ) {
                return 1;
            }
            else if(            (c==str[0])&&!ismetachar(c)            ) {
                return 1;
            }
        }
        else if(        c==str[0]        ) {
            if(            c==45            ) {
                return ((str[-1]==0)||(str[1]==0));
            }
            else {
                return 1;
            }
        }
    } while(    *str++!=0    );
    return 0;
}

void re_print_internal(struct regex_t* pattern, int depth){
int i;
    const char* types[]={
    "UNUSED", "DOT", "BEGIN", "END", "QUESTIONMARK", "STAR", "PLUS", "CHAR",
    "CHAR_CLASS", "INV_CHAR_CLASS", "DIGIT", "NOT_DIGIT", "ALPHA", "NOT_ALPHA",
    "WHITESPACE", "NOT_WHITESPACE", "GROUP"
  };
    while(    pattern!=0&&pattern->type!=(0)    ) {
        for(        i=0        ;        i<depth        ;        ++i        ){
            putchar(32);
        }
        printf("type: %s",types[pattern->type]);
        if(        (pattern->type==(8))||(pattern->type==(9))        ) {
            printf(" [");
            const unsigned char* ccl=pattern->u.ccl;
            while(            *ccl!=0&&*ccl!=93            ) {
                printf("%c",*ccl);
                ++ccl;
            }
            printf("]");
        }
        else if(        pattern->type==(7)        ) {
            printf(" '%c'",pattern->u.ch);
        }
        else if(        pattern->type==(16)        ) {
            printf(" id=%d\n",pattern->u.group.id);
            re_print_internal(pattern->u.group.first,depth+2);
            pattern=pattern->next;
            continue;
        }
        printf("\n");
        pattern=pattern->next;
    }
}

int re_get_group_count(struct re_program* pattern){
struct re_program* program;
    if(    pattern==0    ) {
        return 0;
    }
    program=(struct re_program*)pattern;
    return program->group_count;
}

char* string_lower_case(char* str){
void* __right_value0 = (void*)0;
char* result;
int i;
char* __result_obj__226;
    result=(char*)come_increment_ref_count(__builtin_string(str));
    for(    i=0    ;    i<strlen(str)    ;    i++    ){
        if(        str[i]>=65&&str[i]<=90        ) {
            result[i]=str[i]-65+97;
        }
    }
    __result_obj__226 = (char*)come_increment_ref_count(result);
    (result = come_decrement_ref_count(result, (void*)0, (void*)0, 0, 1, (void*)0));
    (__result_obj__226 = come_decrement_ref_count(__result_obj__226, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__226;
}

char* string_upper_case(char* str){
void* __right_value0 = (void*)0;
char* result;
int i;
char* __result_obj__227;
    result=(char*)come_increment_ref_count(__builtin_string(str));
    for(    i=0    ;    i<strlen(str)    ;    i++    ){
        if(        str[i]>=97&&str[i]<=122        ) {
            result[i]=str[i]-97+65;
        }
    }
    __result_obj__227 = (char*)come_increment_ref_count(result);
    (result = come_decrement_ref_count(result, (void*)0, (void*)0, 0, 1, (void*)0));
    (__result_obj__227 = come_decrement_ref_count(__result_obj__227, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__227;
}

int charp_index_regex(char* self, char* reg, int default_value){
struct re_program* re;
int result;
int offset;
int n;
int result_27;
int matchlength;
int max_captures;
int regex_result;
    if(    reg==((void*)0)    ) {
        return default_value;
    }
    re=re_compile(reg);
    if(    re==((void*)0)    ) {
        return default_value;
    }
    result=default_value;
    offset=0;
    n=0;
    result_27=default_value;
    while(    (_Bool)1    ) {
        matchlength=0;
        max_captures=8;
        struct re_capture captures[max_captures];
        memset(&captures, 0, sizeof(struct re_capture)        *(max_captures)        );
        regex_result=re_matchp(re,self,&matchlength,captures,max_captures);
        if(        regex_result>=0        ) {
            result_27=regex_result;
            break;
        }
        {
            break;
        }
    }
    return result_27;
}

int charp_rindex(char* str, char* search_str, int default_value){
int len;
char* p;
    len=strlen(search_str);
    p=str+strlen(str)-len;
    while(    p>=str    ) {
        if(        strncmp(p,search_str,len)==0        ) {
            return p-str;
        }
        p--;
    }
    return default_value;
}

int charp_rindex_regex(char* self, char* reg, int default_value){
struct re_program* re;
int result;
int offset;
int n;
void* __right_value0 = (void*)0;
char* self2;
int result_28;
int matchlength;
int max_captures;
int regex_result;
int __result_obj__228;
    if(    reg==((void*)0)    ) {
        return default_value;
    }
    re=re_compile(reg);
    if(    re==((void*)0)    ) {
        return default_value;
    }
    result=default_value;
    offset=0;
    n=0;
    self2=(char*)come_increment_ref_count(charp_reverse(self));
    result_28=default_value;
    while(    (_Bool)1    ) {
        matchlength=0;
        max_captures=8;
        struct re_capture captures[max_captures];
        memset(&captures, 0, sizeof(struct re_capture)        *(max_captures)        );
        regex_result=re_matchp(re,self2,&matchlength,captures,max_captures);
        if(        regex_result>=0        ) {
            result_28=strlen(self)-matchlength;
            break;
        }
        {
            break;
        }
    }
    __result_obj__228 = result_28;
    (self2 = come_decrement_ref_count(self2, (void*)0, (void*)0, 0, 0, (void*)0));
    return __result_obj__228;
}

char* charp_strip(char* self){
void* __right_value0 = (void*)0;
char* result;
int len;
char* __result_obj__229;
    result=(char*)come_increment_ref_count(__builtin_string(self));
    len=strlen(self);
    if(    self[len-1]==10    ) {
        result[len-1]=0;
    }
    else if(    self[len-1]==13    ) {
        result[len-1]=0;
    }
    else if(    len>2&&self[len-2]==13&&self[len-1]==10    ) {
        result[len-2]=0;
    }
    __result_obj__229 = (char*)come_increment_ref_count(result);
    (result = come_decrement_ref_count(result, (void*)0, (void*)0, 0, 1, (void*)0));
    (__result_obj__229 = come_decrement_ref_count(__result_obj__229, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__229;
}

int charp_index(char* str, char* search_str, int default_value){
char* head;
    head=strstr(str,search_str);
    if(    head==((void*)0)    ) {
        return default_value;
    }
    return head-str;
}

char* string_chomp(char* str){
void* __right_value0 = (void*)0;
char* result;
char* __result_obj__230;
char* __result_obj__231;
    result=(char*)come_increment_ref_count(__builtin_string(str));
    if(    result[string_length(result)-1]==10    ) {
        __right_value0 = (void*)0;
        __result_obj__230 = (char*)come_increment_ref_count(((char*)(__right_value0=charp_substring(result,0,-2))));
        (result = come_decrement_ref_count(result, (void*)0, (void*)0, 0, 0, (void*)0));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__230 = come_decrement_ref_count(__result_obj__230, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__230;
    }
    __result_obj__231 = (char*)come_increment_ref_count(result);
    (result = come_decrement_ref_count(result, (void*)0, (void*)0, 0, 1, (void*)0));
    (__result_obj__231 = come_decrement_ref_count(__result_obj__231, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__231;
}

char* charp_replace(char* self, int index, char c){
int len;
void* __right_value0 = (void*)0;
char* __result_obj__232;
char* __result_obj__233;
    len=strlen(self);
    if(    strcmp(self,"")==0    ) {
        __result_obj__232 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(self))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__232 = come_decrement_ref_count(__result_obj__232, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__232;
    }
    if(    index<0    ) {
        index+=len;
    }
    if(    index>=len    ) {
        index=len-1;
    }
    if(    index<0    ) {
        index=0;
    }
    self[index]=c;
    __right_value0 = (void*)0;
    __result_obj__233 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(self))));
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__233 = come_decrement_ref_count(__result_obj__233, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__233;
}

char* charp_multiply(char* str, int n){
int len;
void* __right_value0 = (void*)0;
char* result;
int i;
char* __result_obj__234;
    len=strlen(str)*n+1;
    result=(char*)come_increment_ref_count((char*)come_calloc_v2(1, sizeof(char)*(1*(len)), "/usr/local/include/comelang.h", 10973, "char*"));
    result[0]=0;
    for(    i=0    ;    i<n    ;    i++    ){
        strncat(result,str,len);
    }
    __result_obj__234 = (char*)come_increment_ref_count(result);
    (result = come_decrement_ref_count(result, (void*)0, (void*)0, 0, 1, (void*)0));
    (__result_obj__234 = come_decrement_ref_count(__result_obj__234, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__234;
}

struct list$1char$ph* charp_split_str(char* self, char* str){
void* __right_value0 = (void*)0;
void* __right_value1 = (void*)0;
struct list$1char$ph* result;
struct buffer* buf;
int i;
struct list$1char$ph* __result_obj__235;
    result=(struct list$1char$ph*)come_increment_ref_count(list$1char$ph_initialize((struct list$1char$ph*)come_increment_ref_count((struct list$1char$ph*)come_calloc_v2(1, sizeof(struct list$1char$ph)*(1), "/usr/local/include/comelang.h", 10988, "struct list$1char$ph*"))));
    __right_value0 = (void*)0;
    __right_value1 = (void*)0;
    buf=(struct buffer*)come_increment_ref_count(buffer_initialize((struct buffer*)come_increment_ref_count((struct buffer*)come_calloc_v2(1, sizeof(struct buffer)*(1), "/usr/local/include/comelang.h", 10990, "struct buffer*"))));
    for(    i=0    ;    i<charp_length(self)    ;    i++    ){
        if(        strstr(self+i,str)==self+i        ) {
            __right_value0 = (void*)0;
            list$1char$ph_push_back(result,(char*)come_increment_ref_count(__builtin_string(buf->buf)));
            buffer_reset(buf);
            i+=strlen(str)-1;
        }
        else {
            buffer_append_char(buf,self[i]);
        }
    }
    if(    buffer_length(buf)!=0    ) {
        __right_value0 = (void*)0;
        list$1char$ph_push_back(result,(char*)come_increment_ref_count(__builtin_string(buf->buf)));
    }
    __result_obj__235 = (struct list$1char$ph*)come_increment_ref_count(result);
    come_call_finalizer(list$1char$ph$p_finalize, result, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    come_call_finalizer(buffer_finalize, buf, (void*)0, (void*)0, 0, 0, 0, (void*)0);
    come_call_finalizer(list$1char$ph$p_finalize, __result_obj__235, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__235;
}

int string_rindex(char* str, char* search_str, int default_value){
    return charp_rindex(str,search_str,default_value);
}

int string_rindex_regex(char* self, char* reg, int default_value){
    return charp_rindex_regex(self,reg,default_value);
}

char* string_strip(char* self){
void* __right_value0 = (void*)0;
char* __result_obj__236;
    __result_obj__236 = (char*)come_increment_ref_count(((char*)(__right_value0=charp_strip(self))));
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__236 = come_decrement_ref_count(__result_obj__236, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__236;
}

int string_index(char* str, char* search_str, int default_value){
    return charp_index(str,search_str,default_value);
}

int string_index_regex(char* self, char* reg, int default_value){
    return charp_index_regex(self,reg,default_value);
}

char* string_replace(char* self, int index, char c){
void* __right_value0 = (void*)0;
char* __result_obj__237;
    __result_obj__237 = (char*)come_increment_ref_count(((char*)(__right_value0=charp_replace(self,index,c))));
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__237 = come_decrement_ref_count(__result_obj__237, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__237;
}

char* string_multiply(char* str, int n){
void* __right_value0 = (void*)0;
char* __result_obj__238;
    __result_obj__238 = (char*)come_increment_ref_count(((char*)(__right_value0=charp_multiply(str,n))));
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__238 = come_decrement_ref_count(__result_obj__238, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__238;
}

_Bool charp_match(char* self, char* reg){
struct re_program* re;
int offset;
int n;
int matchlength;
int max_captures;
int regex_result;
_Bool __result_obj__239;
_Bool __result_obj__240;
    if(    reg==((void*)0)    ) {
        return (_Bool)0;
    }
    re=re_compile(reg);
    if(    re==((void*)0)    ) {
        return (_Bool)0;
    }
    offset=0;
    n=0;
    matchlength=0;
    max_captures=8;
    struct re_capture captures[max_captures];
    memset(&captures, 0, sizeof(struct re_capture)    *(max_captures)    );
    regex_result=re_matchp(re,self,&matchlength,captures,max_captures);
    if(    regex_result>=0    ) {
        __result_obj__239 = (_Bool)1;
        return __result_obj__239;
    }
    else {
        __result_obj__240 = (_Bool)0;
        return __result_obj__240;
    }
}

static struct list$1char$ph* list$1char$ph_add(struct list$1char$ph* self, char* item){
void* __right_value0 = (void*)0;
struct list_item$1char$ph* litem;
char* __dec_obj20;
struct list_item$1char$ph* litem_29;
char* __dec_obj21;
struct list_item$1char$ph* litem_30;
char* __dec_obj22;
struct list$1char$ph* __result_obj__243;
    if(    self->len==0    ) {
        litem=(struct list_item$1char$ph*)come_increment_ref_count(((struct list_item$1char$ph*)(__right_value0=(struct list_item$1char$ph*)come_calloc_v2(1, sizeof(struct list_item$1char$ph)*(1), "/usr/local/include/comelang.h", 6161, "struct list_item$1char$ph*"))));
        litem->prev=((void*)0);
        litem->next=((void*)0);
        __dec_obj20=litem->item,
        litem->item=(char*)come_increment_ref_count(item);
        __dec_obj20 = come_decrement_ref_count(__dec_obj20, (void*)0, (void*)0, 0,0, (void*)0);
        self->tail=litem;
        self->head=litem;
    }
    else if(    self->len==1    ) {
        __right_value0 = (void*)0;
        litem_29=(struct list_item$1char$ph*)come_increment_ref_count(((struct list_item$1char$ph*)(__right_value0=(struct list_item$1char$ph*)come_calloc_v2(1, sizeof(struct list_item$1char$ph)*(1), "/usr/local/include/comelang.h", 6171, "struct list_item$1char$ph*"))));
        litem_29->prev=self->head;
        litem_29->next=((void*)0);
        __dec_obj21=litem_29->item,
        litem_29->item=(char*)come_increment_ref_count(item);
        __dec_obj21 = come_decrement_ref_count(__dec_obj21, (void*)0, (void*)0, 0,0, (void*)0);
        self->tail=litem_29;
        self->head->next=litem_29;
    }
    else {
        __right_value0 = (void*)0;
        litem_30=(struct list_item$1char$ph*)come_increment_ref_count(((struct list_item$1char$ph*)(__right_value0=(struct list_item$1char$ph*)come_calloc_v2(1, sizeof(struct list_item$1char$ph)*(1), "/usr/local/include/comelang.h", 6181, "struct list_item$1char$ph*"))));
        litem_30->prev=self->tail;
        litem_30->next=((void*)0);
        __dec_obj22=litem_30->item,
        litem_30->item=(char*)come_increment_ref_count(item);
        __dec_obj22 = come_decrement_ref_count(__dec_obj22, (void*)0, (void*)0, 0,0, (void*)0);
        self->tail->next=litem_30;
        self->tail=litem_30;
    }
    self->len++;
    __result_obj__243 = self;
    (item = come_decrement_ref_count(item, (void*)0, (void*)0, 0, 0, (void*)0));
    return __result_obj__243;
}

struct list$1char$ph* charp_scan(char* self, char* reg){
void* __right_value0 = (void*)0;
void* __right_value1 = (void*)0;
struct list$1char$ph* __result_obj__241;
struct list$1char$ph* result;
struct re_program* re;
struct list$1char$ph* __result_obj__242;
int offset;
int n;
int group_count;
int matchlength;
int max_captures;
int regex_result;
char* str;
int i;
struct re_capture cp;
char* match_string;
struct list$1char$ph* __result_obj__244;
    if(    reg==((void*)0)||reg==((void*)0)    ) {
        __result_obj__241 = (struct list$1char$ph*)come_increment_ref_count(((struct list$1char$ph*)(__right_value1=list$1char$ph_initialize((struct list$1char$ph*)come_increment_ref_count((struct list$1char$ph*)come_calloc_v2(1, sizeof(struct list$1char$ph)*(1), "/usr/local/include/comelang.h", 11080, "struct list$1char$ph*"))))));
        come_call_finalizer(list$1char$ph$p_finalize, __right_value1, (void*)0, (void*)0, 0, 1, 0, (void*)0);
        come_call_finalizer(list$1char$ph$p_finalize, __result_obj__241, (void*)0, (void*)0, 0, 0, 1, (void*)0);
        return __result_obj__241;
    }
    __right_value0 = (void*)0;
    __right_value1 = (void*)0;
    result=(struct list$1char$ph*)come_increment_ref_count(list$1char$ph_initialize((struct list$1char$ph*)come_increment_ref_count((struct list$1char$ph*)come_calloc_v2(1, sizeof(struct list$1char$ph)*(1), "/usr/local/include/comelang.h", 11082, "struct list$1char$ph*"))));
    re=re_compile(reg);
    if(    re==((void*)0)    ) {
        __right_value0 = (void*)0;
        __right_value1 = (void*)0;
        __result_obj__242 = (struct list$1char$ph*)come_increment_ref_count(((struct list$1char$ph*)(__right_value1=list$1char$ph_initialize((struct list$1char$ph*)come_increment_ref_count((struct list$1char$ph*)come_calloc_v2(1, sizeof(struct list$1char$ph)*(1), "/usr/local/include/comelang.h", 11087, "struct list$1char$ph*"))))));
        come_call_finalizer(list$1char$ph$p_finalize, result, (void*)0, (void*)0, 0, 0, 0, (void*)0);
        come_call_finalizer(list$1char$ph$p_finalize, __right_value1, (void*)0, (void*)0, 0, 1, 0, (void*)0);
        come_call_finalizer(list$1char$ph$p_finalize, __result_obj__242, (void*)0, (void*)0, 0, 0, 1, (void*)0);
        return __result_obj__242;
    }
    offset=0;
    n=0;
    group_count=re_get_group_count(re);
    while(    (_Bool)1    ) {
        matchlength=0;
        max_captures=8;
        struct re_capture captures[max_captures];
        memset(&captures, 0, sizeof(struct re_capture)        *(max_captures)        );
        regex_result=re_matchp(re,self+offset,&matchlength,captures,max_captures);
        if(        regex_result>=0&&group_count==0        ) {
            __right_value0 = (void*)0;
            str=(char*)come_increment_ref_count(charp_substring(self,offset+regex_result,offset+regex_result+matchlength));
            list$1char$ph_add(result,(char*)come_increment_ref_count(str));
            if(            matchlength==0            ) {
                offset++;
            }
            else {
                offset=offset+regex_result+matchlength;
            }
            (str = come_decrement_ref_count(str, (void*)0, (void*)0, 0, 0, (void*)0));
        }
        else if(        regex_result>=0&&group_count>0        ) {
            for(            i=0            ;            i<group_count            ;            i++            ){
                cp=captures[i];
                __right_value0 = (void*)0;
                match_string=(char*)come_increment_ref_count(charp_substring((self+offset),cp.start,cp.start+cp.length));
                list$1char$ph_push_back(result,(char*)come_increment_ref_count(match_string));
                (match_string = come_decrement_ref_count(match_string, (void*)0, (void*)0, 0, 0, (void*)0));
            }
            if(            matchlength==0            ) {
                offset++;
            }
            else {
                offset=offset+regex_result+matchlength;
            }
        }
        else {
            break;
        }
    }
    __result_obj__244 = (struct list$1char$ph*)come_increment_ref_count(result);
    come_call_finalizer(list$1char$ph$p_finalize, result, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    come_call_finalizer(list$1char$ph$p_finalize, __result_obj__244, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__244;
}

struct list$1char$ph* charp_split(char* self, char* reg){
void* __right_value0 = (void*)0;
void* __right_value1 = (void*)0;
struct list$1char$ph* __result_obj__245;
struct list$1char$ph* result;
struct re_program* re;
struct list$1char$ph* __result_obj__246;
int offset;
int n;
int group_count;
int matchlength;
int max_captures;
int regex_result;
char* str;
char* str_31;
struct list$1char$ph* __result_obj__247;
    if(    reg==((void*)0)||reg==((void*)0)    ) {
        __result_obj__245 = (struct list$1char$ph*)come_increment_ref_count(((struct list$1char$ph*)(__right_value1=list$1char$ph_initialize((struct list$1char$ph*)come_increment_ref_count((struct list$1char$ph*)come_calloc_v2(1, sizeof(struct list$1char$ph)*(1), "/usr/local/include/comelang.h", 11143, "struct list$1char$ph*"))))));
        come_call_finalizer(list$1char$ph$p_finalize, __right_value1, (void*)0, (void*)0, 0, 1, 0, (void*)0);
        come_call_finalizer(list$1char$ph$p_finalize, __result_obj__245, (void*)0, (void*)0, 0, 0, 1, (void*)0);
        return __result_obj__245;
    }
    __right_value0 = (void*)0;
    __right_value1 = (void*)0;
    result=(struct list$1char$ph*)come_increment_ref_count(list$1char$ph_initialize((struct list$1char$ph*)come_increment_ref_count((struct list$1char$ph*)come_calloc_v2(1, sizeof(struct list$1char$ph)*(1), "/usr/local/include/comelang.h", 11146, "struct list$1char$ph*"))));
    re=re_compile(reg);
    if(    re==((void*)0)    ) {
        __right_value0 = (void*)0;
        __right_value1 = (void*)0;
        __result_obj__246 = (struct list$1char$ph*)come_increment_ref_count(((struct list$1char$ph*)(__right_value1=list$1char$ph_initialize((struct list$1char$ph*)come_increment_ref_count((struct list$1char$ph*)come_calloc_v2(1, sizeof(struct list$1char$ph)*(1), "/usr/local/include/comelang.h", 11151, "struct list$1char$ph*"))))));
        come_call_finalizer(list$1char$ph$p_finalize, result, (void*)0, (void*)0, 0, 0, 0, (void*)0);
        come_call_finalizer(list$1char$ph$p_finalize, __right_value1, (void*)0, (void*)0, 0, 1, 0, (void*)0);
        come_call_finalizer(list$1char$ph$p_finalize, __result_obj__246, (void*)0, (void*)0, 0, 0, 1, (void*)0);
        return __result_obj__246;
    }
    offset=0;
    n=0;
    group_count=re_get_group_count(re);
    while(    (_Bool)1    ) {
        matchlength=0;
        max_captures=8;
        struct re_capture captures[max_captures];
        memset(&captures, 0, sizeof(struct re_capture)        *(max_captures)        );
        regex_result=re_matchp(re,self+offset,&matchlength,captures,max_captures);
        if(        regex_result>=0&&group_count==0        ) {
            __right_value0 = (void*)0;
            str=(char*)come_increment_ref_count(charp_substring(self,offset,offset+regex_result));
            list$1char$ph_add(result,(char*)come_increment_ref_count(str));
            if(            matchlength==0            ) {
                offset++;
            }
            else {
                offset=offset+regex_result+matchlength;
            }
            (str = come_decrement_ref_count(str, (void*)0, (void*)0, 0, 0, (void*)0));
        }
        else {
            break;
        }
    }
    if(    offset<charp_length(self)    ) {
        __right_value0 = (void*)0;
        str_31=(char*)come_increment_ref_count(charp_substring(self,offset,-1));
        list$1char$ph_push_back(result,(char*)come_increment_ref_count(str_31));
        (str_31 = come_decrement_ref_count(str_31, (void*)0, (void*)0, 0, 0, (void*)0));
    }
    __result_obj__247 = (struct list$1char$ph*)come_increment_ref_count(result);
    come_call_finalizer(list$1char$ph$p_finalize, result, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    come_call_finalizer(list$1char$ph$p_finalize, __result_obj__247, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__247;
}

char* string_sub(char* self, char* reg, char* replace){
void* __right_value0 = (void*)0;
char* __result_obj__248;
    __result_obj__248 = (char*)come_increment_ref_count(((char*)(__right_value0=charp_sub(self,reg,replace))));
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__248 = come_decrement_ref_count(__result_obj__248, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__248;
}

struct list$1char$ph* string_split_str(char* self, char* str){
void* __right_value0 = (void*)0;
struct list$1char$ph* __result_obj__249;
    __result_obj__249 = (struct list$1char$ph*)come_increment_ref_count(((struct list$1char$ph*)(__right_value0=charp_split_str(self,str))));
    come_call_finalizer(list$1char$ph$p_finalize, __right_value0, (void*)0, (void*)0, 0, 1, 0, (void*)0);
    come_call_finalizer(list$1char$ph$p_finalize, __result_obj__249, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__249;
}

struct list$1char$ph* string_scan(char* self, char* reg){
void* __right_value0 = (void*)0;
struct list$1char$ph* __result_obj__250;
    __result_obj__250 = (struct list$1char$ph*)come_increment_ref_count(((struct list$1char$ph*)(__right_value0=charp_scan(self,reg))));
    come_call_finalizer(list$1char$ph$p_finalize, __right_value0, (void*)0, (void*)0, 0, 1, 0, (void*)0);
    come_call_finalizer(list$1char$ph$p_finalize, __result_obj__250, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__250;
}

struct list$1char$ph* string_split(char* self, char* reg){
void* __right_value0 = (void*)0;
struct list$1char$ph* __result_obj__251;
    __result_obj__251 = (struct list$1char$ph*)come_increment_ref_count(((struct list$1char$ph*)(__right_value0=charp_split(self,reg))));
    come_call_finalizer(list$1char$ph$p_finalize, __right_value0, (void*)0, (void*)0, 0, 1, 0, (void*)0);
    come_call_finalizer(list$1char$ph$p_finalize, __result_obj__251, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__251;
}

_Bool string_match(char* self, char* reg){
    return charp_match(self,reg);
}

char* charp_sub(char* self, char* reg, char* replace){
void* __right_value0 = (void*)0;
char* __result_obj__252;
struct re_program* re;
char* __result_obj__253;
int offset;
int n;
void* __right_value1 = (void*)0;
struct buffer* result;
int group_count;
int matchlength;
int max_captures;
int regex_result;
char* str;
char* str_32;
char* __result_obj__254;
    if(    reg==((void*)0)||reg==((void*)0)    ) {
        __result_obj__252 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__252 = come_decrement_ref_count(__result_obj__252, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__252;
    }
    re=re_compile(reg);
    if(    re==((void*)0)    ) {
        __right_value0 = (void*)0;
        __result_obj__253 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__253 = come_decrement_ref_count(__result_obj__253, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__253;
    }
    offset=0;
    n=0;
    __right_value0 = (void*)0;
    result=(struct buffer*)come_increment_ref_count(buffer_initialize((struct buffer*)come_increment_ref_count((struct buffer*)come_calloc_v2(1, sizeof(struct buffer)*(1), "/usr/local/include/comelang.h", 11236, "struct buffer*"))));
    group_count=re_get_group_count(re);
    while(    (_Bool)1    ) {
        matchlength=0;
        max_captures=8;
        struct re_capture captures[max_captures];
        memset(&captures, 0, sizeof(struct re_capture)        *(max_captures)        );
        regex_result=re_matchp(re,self+offset,&matchlength,captures,max_captures);
        if(        regex_result>=0&&group_count==0        ) {
            __right_value0 = (void*)0;
            str=(char*)come_increment_ref_count(charp_substring(self,offset,offset+regex_result));
            buffer_append_str(result,str);
            buffer_append_str(result,replace);
            if(            matchlength==0            ) {
                offset++;
            }
            else {
                offset=offset+regex_result+matchlength;
            }
            (str = come_decrement_ref_count(str, (void*)0, (void*)0, 0, 0, (void*)0));
        }
        else {
            __right_value0 = (void*)0;
            str_32=(char*)come_increment_ref_count(charp_substring(self,offset,-1));
            buffer_append_str(result,str_32);
            (str_32 = come_decrement_ref_count(str_32, (void*)0, (void*)0, 0, 0, (void*)0));
            break;
            (str_32 = come_decrement_ref_count(str_32, (void*)0, (void*)0, 0, 0, (void*)0));
        }
    }
    __right_value0 = (void*)0;
    __result_obj__254 = (char*)come_increment_ref_count(((char*)(__right_value0=buffer_to_string(result))));
    come_call_finalizer(buffer_finalize, result, (void*)0, (void*)0, 0, 0, 0, (void*)0);
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__254 = come_decrement_ref_count(__result_obj__254, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__254;
}

char* charp_sub_block(char* self, char* reg, void* parent, char* (*block)(void*,char*,struct list$1char$ph*)){
void* __right_value0 = (void*)0;
char* __result_obj__255;
void* __right_value1 = (void*)0;
struct buffer* result;
struct re_program* re;
char* __result_obj__256;
int offset;
int n;
int group_count;
int matchlength;
int max_captures;
int regex_result;
char* str;
struct list$1char$ph* group_strings;
char* match_string;
char* block_result;
char* str_33;
struct list$1char$ph* group_strings_34;
int i;
struct re_capture cp;
char* match_string_35;
char* match_string_36;
char* block_result_37;
char* str_38;
char* __result_obj__257;
    if(    reg==((void*)0)||reg==((void*)0)    ) {
        __result_obj__255 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__255 = come_decrement_ref_count(__result_obj__255, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__255;
    }
    __right_value0 = (void*)0;
    result=(struct buffer*)come_increment_ref_count(buffer_initialize((struct buffer*)come_increment_ref_count((struct buffer*)come_calloc_v2(1, sizeof(struct buffer)*(1), "/usr/local/include/comelang.h", 11278, "struct buffer*"))));
    re=re_compile(reg);
    if(    re==((void*)0)    ) {
        __right_value0 = (void*)0;
        __result_obj__256 = (char*)come_increment_ref_count(((char*)(__right_value0=__builtin_string(""))));
        come_call_finalizer(buffer_finalize, result, (void*)0, (void*)0, 0, 0, 0, (void*)0);
        (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
        (__result_obj__256 = come_decrement_ref_count(__result_obj__256, (void*)0, (void*)0, 0, 1, (void*)0));
        return __result_obj__256;
    }
    offset=0;
    n=0;
    group_count=re_get_group_count(re);
    while(    (_Bool)1    ) {
        matchlength=0;
        max_captures=8;
        struct re_capture captures[max_captures];
        memset(&captures, 0, sizeof(struct re_capture)        *(max_captures)        );
        regex_result=re_matchp(re,self+offset,&matchlength,captures,max_captures);
        if(        regex_result>=0&&group_count==0        ) {
            __right_value0 = (void*)0;
            str=(char*)come_increment_ref_count(charp_substring(self,offset,offset+regex_result));
            buffer_append_str(result,str);
            __right_value0 = (void*)0;
            __right_value1 = (void*)0;
            group_strings=(struct list$1char$ph*)come_increment_ref_count(list$1char$ph_initialize((struct list$1char$ph*)come_increment_ref_count((struct list$1char$ph*)come_calloc_v2(1, sizeof(struct list$1char$ph)*(1), "/usr/local/include/comelang.h", 11305, "struct list$1char$ph*"))));
            __right_value0 = (void*)0;
            match_string=(char*)come_increment_ref_count(charp_substring(self,offset+regex_result,offset+regex_result+matchlength));
            __right_value0 = (void*)0;
            block_result=(char*)come_increment_ref_count(block(parent,match_string,group_strings));
            buffer_append_str(result,block_result);
            if(            matchlength==0            ) {
                offset++;
            }
            else {
                offset=offset+regex_result+matchlength;
            }
            (str = come_decrement_ref_count(str, (void*)0, (void*)0, 0, 0, (void*)0));
            come_call_finalizer(list$1char$ph$p_finalize, group_strings, (void*)0, (void*)0, 0, 0, 0, (void*)0);
            (match_string = come_decrement_ref_count(match_string, (void*)0, (void*)0, 0, 0, (void*)0));
            (block_result = come_decrement_ref_count(block_result, (void*)0, (void*)0, 0, 0, (void*)0));
        }
        else if(        regex_result>=0&&group_count>0        ) {
            __right_value0 = (void*)0;
            str_33=(char*)come_increment_ref_count(charp_substring(self,offset,offset+regex_result));
            buffer_append_str(result,str_33);
            __right_value0 = (void*)0;
            __right_value1 = (void*)0;
            group_strings_34=(struct list$1char$ph*)come_increment_ref_count(list$1char$ph_initialize((struct list$1char$ph*)come_increment_ref_count((struct list$1char$ph*)come_calloc_v2(1, sizeof(struct list$1char$ph)*(1), "/usr/local/include/comelang.h", 11327, "struct list$1char$ph*"))));
            for(            i=0            ;            i<group_count            ;            i++            ){
                cp=captures[i];
                __right_value0 = (void*)0;
                match_string_35=(char*)come_increment_ref_count(charp_substring((self+offset),cp.start,cp.start+cp.length));
                list$1char$ph_push_back(group_strings_34,(char*)come_increment_ref_count(match_string_35));
                (match_string_35 = come_decrement_ref_count(match_string_35, (void*)0, (void*)0, 0, 0, (void*)0));
            }
            __right_value0 = (void*)0;
            match_string_36=(char*)come_increment_ref_count(charp_substring(self,offset+regex_result,offset+regex_result+matchlength));
            __right_value0 = (void*)0;
            block_result_37=(char*)come_increment_ref_count(block(parent,match_string_36,group_strings_34));
            buffer_append_str(result,block_result_37);
            if(            matchlength==0            ) {
                offset++;
            }
            else {
                offset=offset+regex_result+matchlength;
            }
            (str_33 = come_decrement_ref_count(str_33, (void*)0, (void*)0, 0, 0, (void*)0));
            come_call_finalizer(list$1char$ph$p_finalize, group_strings_34, (void*)0, (void*)0, 0, 0, 0, (void*)0);
            (match_string_36 = come_decrement_ref_count(match_string_36, (void*)0, (void*)0, 0, 0, (void*)0));
            (block_result_37 = come_decrement_ref_count(block_result_37, (void*)0, (void*)0, 0, 0, (void*)0));
        }
        else {
            __right_value0 = (void*)0;
            str_38=(char*)come_increment_ref_count(charp_substring(self,offset,-1));
            buffer_append_str(result,str_38);
            (str_38 = come_decrement_ref_count(str_38, (void*)0, (void*)0, 0, 0, (void*)0));
            break;
            (str_38 = come_decrement_ref_count(str_38, (void*)0, (void*)0, 0, 0, (void*)0));
        }
    }
    __right_value0 = (void*)0;
    __result_obj__257 = (char*)come_increment_ref_count(((char*)(__right_value0=buffer_to_string(result))));
    come_call_finalizer(buffer_finalize, result, (void*)0, (void*)0, 0, 0, 0, (void*)0);
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__257 = come_decrement_ref_count(__result_obj__257, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__257;
}

struct list$1char$ph* charp_scan_block(char* self, char* reg, void* parent, char* (*block)(void*,char*,struct list$1char$ph*)){
void* __right_value0 = (void*)0;
void* __right_value1 = (void*)0;
struct list$1char$ph* __result_obj__258;
struct list$1char$ph* result;
struct re_program* re;
struct list$1char$ph* __result_obj__259;
int offset;
int n;
int group_count;
int matchlength;
int max_captures;
int regex_result;
struct list$1char$ph* group_strings;
char* match_string;
char* block_result;
struct list$1char$ph* group_strings_39;
int i;
struct re_capture cp;
char* match_string_40;
char* match_string_41;
char* block_result_42;
struct list$1char$ph* __result_obj__260;
    if(    reg==((void*)0)||reg==((void*)0)    ) {
        __result_obj__258 = (struct list$1char$ph*)come_increment_ref_count(((struct list$1char$ph*)(__right_value1=list$1char$ph_initialize((struct list$1char$ph*)come_increment_ref_count((struct list$1char$ph*)come_calloc_v2(1, sizeof(struct list$1char$ph)*(1), "/usr/local/include/comelang.h", 11361, "struct list$1char$ph*"))))));
        come_call_finalizer(list$1char$ph$p_finalize, __right_value1, (void*)0, (void*)0, 0, 1, 0, (void*)0);
        come_call_finalizer(list$1char$ph$p_finalize, __result_obj__258, (void*)0, (void*)0, 0, 0, 1, (void*)0);
        return __result_obj__258;
    }
    __right_value0 = (void*)0;
    __right_value1 = (void*)0;
    result=(struct list$1char$ph*)come_increment_ref_count(list$1char$ph_initialize((struct list$1char$ph*)come_increment_ref_count((struct list$1char$ph*)come_calloc_v2(1, sizeof(struct list$1char$ph)*(1), "/usr/local/include/comelang.h", 11363, "struct list$1char$ph*"))));
    re=re_compile(reg);
    if(    re==((void*)0)    ) {
        __right_value0 = (void*)0;
        __right_value1 = (void*)0;
        __result_obj__259 = (struct list$1char$ph*)come_increment_ref_count(((struct list$1char$ph*)(__right_value1=list$1char$ph_initialize((struct list$1char$ph*)come_increment_ref_count((struct list$1char$ph*)come_calloc_v2(1, sizeof(struct list$1char$ph)*(1), "/usr/local/include/comelang.h", 11368, "struct list$1char$ph*"))))));
        come_call_finalizer(list$1char$ph$p_finalize, result, (void*)0, (void*)0, 0, 0, 0, (void*)0);
        come_call_finalizer(list$1char$ph$p_finalize, __right_value1, (void*)0, (void*)0, 0, 1, 0, (void*)0);
        come_call_finalizer(list$1char$ph$p_finalize, __result_obj__259, (void*)0, (void*)0, 0, 0, 1, (void*)0);
        return __result_obj__259;
    }
    offset=0;
    n=0;
    group_count=re_get_group_count(re);
    while(    (_Bool)1    ) {
        matchlength=0;
        max_captures=8;
        struct re_capture captures[max_captures];
        memset(&captures, 0, sizeof(struct re_capture)        *(max_captures)        );
        regex_result=re_matchp(re,self+offset,&matchlength,captures,max_captures);
        if(        regex_result>=0&&group_count==0        ) {
            __right_value0 = (void*)0;
            __right_value1 = (void*)0;
            group_strings=(struct list$1char$ph*)come_increment_ref_count(list$1char$ph_initialize((struct list$1char$ph*)come_increment_ref_count((struct list$1char$ph*)come_calloc_v2(1, sizeof(struct list$1char$ph)*(1), "/usr/local/include/comelang.h", 11386, "struct list$1char$ph*"))));
            __right_value0 = (void*)0;
            match_string=(char*)come_increment_ref_count(charp_substring(self,offset+regex_result,offset+regex_result+matchlength));
            __right_value0 = (void*)0;
            block_result=(char*)come_increment_ref_count(block(parent,match_string,group_strings));
            list$1char$ph_add(result,(char*)come_increment_ref_count(block_result));
            if(            matchlength==0            ) {
                offset++;
            }
            else {
                offset=offset+regex_result+matchlength;
            }
            come_call_finalizer(list$1char$ph$p_finalize, group_strings, (void*)0, (void*)0, 0, 0, 0, (void*)0);
            (match_string = come_decrement_ref_count(match_string, (void*)0, (void*)0, 0, 0, (void*)0));
            (block_result = come_decrement_ref_count(block_result, (void*)0, (void*)0, 0, 0, (void*)0));
        }
        else if(        regex_result>=0&&group_count>0        ) {
            __right_value0 = (void*)0;
            __right_value1 = (void*)0;
            group_strings_39=(struct list$1char$ph*)come_increment_ref_count(list$1char$ph_initialize((struct list$1char$ph*)come_increment_ref_count((struct list$1char$ph*)come_calloc_v2(1, sizeof(struct list$1char$ph)*(1), "/usr/local/include/comelang.h", 11403, "struct list$1char$ph*"))));
            for(            i=0            ;            i<group_count            ;            i++            ){
                cp=captures[i];
                __right_value0 = (void*)0;
                match_string_40=(char*)come_increment_ref_count(charp_substring((self+offset),cp.start,cp.start+cp.length));
                list$1char$ph_push_back(group_strings_39,(char*)come_increment_ref_count(match_string_40));
                (match_string_40 = come_decrement_ref_count(match_string_40, (void*)0, (void*)0, 0, 0, (void*)0));
            }
            __right_value0 = (void*)0;
            match_string_41=(char*)come_increment_ref_count(charp_substring(self,offset+regex_result,offset+regex_result+matchlength));
            __right_value0 = (void*)0;
            block_result_42=(char*)come_increment_ref_count(block(parent,match_string_41,group_strings_39));
            list$1char$ph_add(result,(char*)come_increment_ref_count(block_result_42));
            if(            matchlength==0            ) {
                offset++;
            }
            else {
                offset=offset+regex_result+matchlength;
            }
            come_call_finalizer(list$1char$ph$p_finalize, group_strings_39, (void*)0, (void*)0, 0, 0, 0, (void*)0);
            (match_string_41 = come_decrement_ref_count(match_string_41, (void*)0, (void*)0, 0, 0, (void*)0));
            (block_result_42 = come_decrement_ref_count(block_result_42, (void*)0, (void*)0, 0, 0, (void*)0));
        }
        else {
            break;
        }
    }
    __result_obj__260 = (struct list$1char$ph*)come_increment_ref_count(result);
    come_call_finalizer(list$1char$ph$p_finalize, result, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    come_call_finalizer(list$1char$ph$p_finalize, __result_obj__260, (void*)0, (void*)0, 0, 0, 1, (void*)0);
    return __result_obj__260;
}

char* string_sub_block(char* self, char* reg, void* parent, char* (*block)(void*,char*,struct list$1char$ph*)){
void* __right_value0 = (void*)0;
char* __result_obj__261;
    __result_obj__261 = (char*)come_increment_ref_count(((char*)(__right_value0=charp_sub_block(self,reg,parent,block))));
    (__right_value0 = come_decrement_ref_count(__right_value0, (void*)0, (void*)0, 1, 0, (void*)0));
    (__result_obj__261 = come_decrement_ref_count(__result_obj__261, (void*)0, (void*)0, 0, 1, (void*)0));
    return __result_obj__261;
}

