#ifndef SAMOSC_DOCTEST

#if defined(DOCTEST_CONFIG_IMPLEMENT) || !defined(DOCTEST_SINGLE_HEADER)

#ifndef DOCTEST_SINGLE_HEADER
#include "doctest_fwd.h"
#endif// DOCTEST_SINGLE_HEADER

DOCTEST_CLANG_SUPPRESS_WARNING_WITH_PUSH("-Wunused-macros")

#ifndef DOCTEST_LIBRARY_IMPLEMENTATION
#define DOCTEST_LIBRARY_IMPLEMENTATION

DOCTEST_CLANG_SUPPRESS_WARNING_POP

DOCTEST_SUPPRESS_COMMON_WARNINGS_PUSH

DOCTEST_CLANG_SUPPRESS_WARNING_PUSH
DOCTEST_CLANG_SUPPRESS_WARNING("-Wglobal-constructors")
DOCTEST_CLANG_SUPPRESS_WARNING("-Wexit-time-destructors")
DOCTEST_CLANG_SUPPRESS_WARNING("-Wsign-conversion")
DOCTEST_CLANG_SUPPRESS_WARNING("-Wshorten-64-to-32")
DOCTEST_CLANG_SUPPRESS_WARNING("-Wmissing-variable-declarations")
DOCTEST_CLANG_SUPPRESS_WARNING("-Wswitch")
DOCTEST_CLANG_SUPPRESS_WARNING("-Wswitch-enum")
DOCTEST_CLANG_SUPPRESS_WARNING("-Wcovered-switch-default")
DOCTEST_CLANG_SUPPRESS_WARNING("-Wmissing-noreturn")
DOCTEST_CLANG_SUPPRESS_WARNING("-Wdisabled-macro-expansion")
DOCTEST_CLANG_SUPPRESS_WARNING("-Wmissing-braces")
DOCTEST_CLANG_SUPPRESS_WARNING("-Wmissing-field-initializers")
DOCTEST_CLANG_SUPPRESS_WARNING("-Wunused-member-function")
DOCTEST_CLANG_SUPPRESS_WARNING("-Wnonportable-system-include-path")

DOCTEST_GCC_SUPPRESS_WARNING_PUSH
DOCTEST_GCC_SUPPRESS_WARNING("-Wconversion")
DOCTEST_GCC_SUPPRESS_WARNING("-Wsign-conversion")
DOCTEST_GCC_SUPPRESS_WARNING("-Wmissing-field-initializers")
DOCTEST_GCC_SUPPRESS_WARNING("-Wmissing-braces")
DOCTEST_GCC_SUPPRESS_WARNING("-Wswitch")
DOCTEST_GCC_SUPPRESS_WARNING("-Wswitch-enum")
DOCTEST_GCC_SUPPRESS_WARNING("-Wswitch-default")
DOCTEST_GCC_SUPPRESS_WARNING("-Wunsafe-loop-optimizations")
DOCTEST_GCC_SUPPRESS_WARNING("-Wold-style-cast")
DOCTEST_GCC_SUPPRESS_WARNING("-Wunused-function")
DOCTEST_GCC_SUPPRESS_WARNING("-Wmultiple-inheritance")
DOCTEST_GCC_SUPPRESS_WARNING("-Wsuggest-attribute")

DOCTEST_MSVC_SUPPRESS_WARNING_PUSH
DOCTEST_MSVC_SUPPRESS_WARNING(4267)// 'var' : conversion from 'x' to 'y', possible loss of data
DOCTEST_MSVC_SUPPRESS_WARNING(4530)// C++ exception handler used, but unwind semantics not enabled
DOCTEST_MSVC_SUPPRESS_WARNING(4577)// 'noexcept' used with no exception handling mode specified
DOCTEST_MSVC_SUPPRESS_WARNING(4774)// format string expected in argument is not a string literal
DOCTEST_MSVC_SUPPRESS_WARNING(4365)// conversion from 'int' to 'unsigned', signed/unsigned mismatch
DOCTEST_MSVC_SUPPRESS_WARNING(5039)// pointer to potentially throwing function passed to extern C
DOCTEST_MSVC_SUPPRESS_WARNING(4800)// forcing value to bool 'true' or 'false' (performance warning)
DOCTEST_MSVC_SUPPRESS_WARNING(5245)// unreferenced function with internal linkage has been removed

DOCTEST_MAKE_STD_HEADERS_CLEAN_FROM_WARNINGS_ON_WALL_BEGIN

// required includes - will go only in one translation unit!
#include <climits>
#include <cmath>
#include <ctime>
// borland (Embarcadero) compiler requires math.h and not cmath - https://github.com/doctest/doctest/pull/37
#ifdef __BORLANDC__
#include <math.h>
#endif// __BORLANDC__
#include <algorithm>
#include <atomic>
#include <cctype>
#include <cfloat>
#include <csignal>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <mutex>
#include <new>
#include <set>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <vector>

#ifdef DOCTEST_PLATFORM_MAC
#include <sys/sysctl.h>
#include <sys/types.h>
#include <unistd.h>
#endif// DOCTEST_PLATFORM_MAC

#ifdef DOCTEST_PLATFORM_WINDOWS

// defines for a leaner windows.h
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif// WIN32_LEAN_AND_MEAN
#ifndef NOMINMAX
#define NOMINMAX
#endif// NOMINMAX

// not sure what AfxWin.h is for - here I do what Catch does
#ifdef __AFXDLL
#include <AfxWin.h>
#else
#include <windows.h>
#endif
#include <io.h>

#else// DOCTEST_PLATFORM_WINDOWS

#include <sys/time.h>
#include <unistd.h>

#endif// DOCTEST_PLATFORM_WINDOWS

// this is a fix for https://github.com/doctest/doctest/issues/348
// https://mail.gnome.org/archives/xml/2012-January/msg00000.html
#if !defined(HAVE_UNISTD_H) && !defined(STDOUT_FILENO)
#define STDOUT_FILENO fileno(stdout)
#endif// HAVE_UNISTD_H

DOCTEST_MAKE_STD_HEADERS_CLEAN_FROM_WARNINGS_ON_WALL_END

// counts the number of elements in a C array
#define DOCTEST_COUNTOF(x) (sizeof(x) / sizeof(x[0]))

#ifdef DOCTEST_CONFIG_DISABLE
#define DOCTEST_BRANCH_ON_DISABLED(if_disabled, if_not_disabled) if_disabled
#else// DOCTEST_CONFIG_DISABLE
#define DOCTEST_BRANCH_ON_DISABLED(if_disabled, if_not_disabled) if_not_disabled
#endif// DOCTEST_CONFIG_DISABLE

#ifndef DOCTEST_CONFIG_OPTIONS_PREFIX
#define DOCTEST_CONFIG_OPTIONS_PREFIX "dt-"
#endif

#ifndef DOCTEST_THREAD_LOCAL
#if DOCTEST_MSVC && (DOCTEST_MSVC < DOCTEST_COMPILER(19, 0, 0))
#define DOCTEST_THREAD_LOCAL
#else// DOCTEST_MSVC
#define DOCTEST_THREAD_LOCAL thread_local
#endif// DOCTEST_MSVC
#endif// DOCTEST_THREAD_LOCAL

#ifndef DOCTEST_MULTI_LANE_ATOMICS_THREAD_LANES
#define DOCTEST_MULTI_LANE_ATOMICS_THREAD_LANES 32
#endif

#ifndef DOCTEST_MULTI_LANE_ATOMICS_CACHE_LINE_SIZE
#define DOCTEST_MULTI_LANE_ATOMICS_CACHE_LINE_SIZE 64
#endif

#ifdef DOCTEST_CONFIG_NO_UNPREFIXED_OPTIONS
#define DOCTEST_OPTIONS_PREFIX_DISPLAY DOCTEST_CONFIG_OPTIONS_PREFIX
#else
#define DOCTEST_OPTIONS_PREFIX_DISPLAY ""
#endif

#if defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_APP)
#define DOCTEST_CONFIG_NO_MULTI_LANE_ATOMICS
#endif

#ifndef DOCTEST_CDECL
#define DOCTEST_CDECL __cdecl
#endif

namespace doctest {

  bool is_running_in_test = false;

  namespace {
    using namespace detail;

    template<typename Ex>
    DOCTEST_NORETURN void throw_exception(Ex const &e) {
#ifndef DOCTEST_CONFIG_NO_EXCEPTIONS
      throw e;
#else // DOCTEST_CONFIG_NO_EXCEPTIONS
      std::cerr << "doctest will terminate because it needed to throw an exception.\n"
                << "The message was: " << e.what() << '\n';
      std::terminate();
#endif// DOCTEST_CONFIG_NO_EXCEPTIONS
    }

#ifndef DOCTEST_INTERNAL_ERROR
#define DOCTEST_INTERNAL_ERROR(msg) \
  throw_exception(std::logic_error( \
          __FILE__ ":" DOCTEST_TOSTR(__LINE__) ": Internal doctest error: " msg))
#endif// DOCTEST_INTERNAL_ERROR

    // case insensitive strcmp
    int stricmp(const char *a, const char *b) {
      for (;; a++, b++) {
        const int d = tolower(*a) - tolower(*b);
        if (d != 0 || !*a)
          return d;
      }
    }

    template<typename T>
    String fpToString(T value, int precision) {
      std::ostringstream oss;
      oss << std::setprecision(precision) << std::fixed << value;
      std::string d = oss.str();
      size_t i = d.find_last_not_of('0');
      if (i != std::string::npos && i != d.size() - 1) {
        if (d[i] == '.')
          i++;
        d = d.substr(0, i + 1);
      }
      return d.c_str();
    }

    struct Endianness {
      enum Arch {
        Big,
        Little
      };

      static Arch which() {
        int x = 1;
        // casting any data pointer to char* is allowed
        auto ptr = reinterpret_cast<char *>(&x);
        if (*ptr)
          return Little;
        return Big;
      }
    };
  }// namespace

  namespace detail {
    String rawMemoryToString(const void *object, unsigned size) {
      // Reverse order for little endian architectures
      int i = 0, end = static_cast<int>(size), inc = 1;
      if (Endianness::which() == Endianness::Little) {
        i = end - 1;
        end = inc = -1;
      }

      unsigned const char *bytes = static_cast<unsigned const char *>(object);
      std::ostream *oss = tlssPush();
      *oss << "0x" << std::setfill('0') << std::hex;
      for (; i != end; i += inc)
        *oss << std::setw(2) << static_cast<unsigned>(bytes[i]);
      return tlssPop();
    }

    DOCTEST_THREAD_LOCAL class
    {
      std::vector<std::streampos> stack;
      std::stringstream ss;

  public:
      std::ostream *push() {
        stack.push_back(ss.tellp());
        return &ss;
      }

      String pop() {
        if (stack.empty())
          DOCTEST_INTERNAL_ERROR("TLSS was empty when trying to pop!");

        std::streampos pos = stack.back();
        stack.pop_back();
        unsigned sz = static_cast<unsigned>(ss.tellp() - pos);
        ss.rdbuf()->pubseekpos(pos, std::ios::in | std::ios::out);
        return String(ss, sz);
      }
    } g_oss;

    std::ostream *tlssPush() {
      return g_oss.push();
    }

    String tlssPop() {
      return g_oss.pop();
    }

#ifndef DOCTEST_CONFIG_DISABLE

    namespace timer_large_integer {

#if defined(DOCTEST_PLATFORM_WINDOWS)
      typedef ULONGLONG type;
#else // DOCTEST_PLATFORM_WINDOWS
      typedef std::uint64_t type;
#endif// DOCTEST_PLATFORM_WINDOWS
    } // namespace timer_large_integer

    typedef timer_large_integer::type ticks_t;

#ifdef DOCTEST_CONFIG_GETCURRENTTICKS
    ticks_t getCurrentTicks() { return DOCTEST_CONFIG_GETCURRENTTICKS(); }
#elif defined(DOCTEST_PLATFORM_WINDOWS)
    ticks_t getCurrentTicks() {
      static LARGE_INTEGER hz = {0}, hzo = {0};
      if (!hz.QuadPart) {
        QueryPerformanceFrequency(&hz);
        QueryPerformanceCounter(&hzo);
      }
      LARGE_INTEGER t;
      QueryPerformanceCounter(&t);
      return ((t.QuadPart - hzo.QuadPart) * LONGLONG(1000000)) / hz.QuadPart;
    }
#else // DOCTEST_PLATFORM_WINDOWS
    ticks_t getCurrentTicks() {
      timeval t;
      gettimeofday(&t, nullptr);
      return static_cast<ticks_t>(t.tv_sec) * 1000000 + static_cast<ticks_t>(t.tv_usec);
    }
#endif// DOCTEST_PLATFORM_WINDOWS

    struct Timer {
      void start() { m_ticks = getCurrentTicks(); }
      unsigned int getElapsedMicroseconds() const {
        return static_cast<unsigned int>(getCurrentTicks() - m_ticks);
      }
      //unsigned int getElapsedMilliseconds() const {
      //    return static_cast<unsigned int>(getElapsedMicroseconds() / 1000);
      //}
      double getElapsedSeconds() const { return static_cast<double>(getCurrentTicks() - m_ticks) / 1000000.0; }

  private:
      ticks_t m_ticks = 0;
    };

#ifdef DOCTEST_CONFIG_NO_MULTI_LANE_ATOMICS
    template<typename T>
    using AtomicOrMultiLaneAtomic = std::atomic<T>;
#else // DOCTEST_CONFIG_NO_MULTI_LANE_ATOMICS
    // Provides a multilane implementation of an atomic variable that supports add, sub, load,
    // store. Instead of using a single atomic variable, this splits up into multiple ones,
    // each sitting on a separate cache line. The goal is to provide a speedup when most
    // operations are modifying. It achieves this with two properties:
    //
    // * Multiple atomics are used, so chance of congestion from the same atomic is reduced.
    // * Each atomic sits on a separate cache line, so false sharing is reduced.
    //
    // The disadvantage is that there is a small overhead due to the use of TLS, and load/store
    // is slower because all atomics have to be accessed.
    template<typename T>
    class MultiLaneAtomic {
      struct CacheLineAlignedAtomic {
        std::atomic<T> atomic{};
        char padding[DOCTEST_MULTI_LANE_ATOMICS_CACHE_LINE_SIZE - sizeof(std::atomic<T>)];
      };
      CacheLineAlignedAtomic m_atomics[DOCTEST_MULTI_LANE_ATOMICS_THREAD_LANES];

      static_assert(sizeof(CacheLineAlignedAtomic) == DOCTEST_MULTI_LANE_ATOMICS_CACHE_LINE_SIZE,
                    "guarantee one atomic takes exactly one cache line");

  public:
      T operator++() DOCTEST_NOEXCEPT { return fetch_add(1) + 1; }

      T operator++(int) DOCTEST_NOEXCEPT { return fetch_add(1); }

      T fetch_add(T arg, std::memory_order order = std::memory_order_seq_cst) DOCTEST_NOEXCEPT {
        return myAtomic().fetch_add(arg, order);
      }

      T fetch_sub(T arg, std::memory_order order = std::memory_order_seq_cst) DOCTEST_NOEXCEPT {
        return myAtomic().fetch_sub(arg, order);
      }

      operator T() const DOCTEST_NOEXCEPT { return load(); }

      T load(std::memory_order order = std::memory_order_seq_cst) const DOCTEST_NOEXCEPT {
        auto result = T();
        for (auto const &c: m_atomics) {
          result += c.atomic.load(order);
        }
        return result;
      }

      T operator=(T desired) DOCTEST_NOEXCEPT {// lgtm [cpp/assignment-does-not-return-this]
        store(desired);
        return desired;
      }

      void store(T desired, std::memory_order order = std::memory_order_seq_cst) DOCTEST_NOEXCEPT {
        // first value becomes desired", all others become 0.
        for (auto &c: m_atomics) {
          c.atomic.store(desired, order);
          desired = {};
        }
      }

  private:
      // Each thread has a different atomic that it operates on. If more than NumLanes threads
      // use this, some will use the same atomic. So performance will degrade a bit, but still
      // everything will work.
      //
      // The logic here is a bit tricky. The call should be as fast as possible, so that there
      // is minimal to no overhead in determining the correct atomic for the current thread.
      //
      // 1. A global static counter laneCounter counts continuously up.
      // 2. Each successive thread will use modulo operation of that counter so it gets an atomic
      //    assigned in a round-robin fashion.
      // 3. This tlsLaneIdx is stored in the thread local data, so it is directly available with
      //    little overhead.
      std::atomic<T> &myAtomic() DOCTEST_NOEXCEPT {
        static std::atomic<size_t> laneCounter;
        DOCTEST_THREAD_LOCAL size_t tlsLaneIdx =
                laneCounter++ % DOCTEST_MULTI_LANE_ATOMICS_THREAD_LANES;

        return m_atomics[tlsLaneIdx].atomic;
      }
    };

    template<typename T>
    using AtomicOrMultiLaneAtomic = MultiLaneAtomic<T>;
#endif// DOCTEST_CONFIG_NO_MULTI_LANE_ATOMICS

    // this holds both parameters from the command line and runtime data for tests
    struct ContextState : ContextOptions, TestRunStats, CurrentTestCaseStats {
      AtomicOrMultiLaneAtomic<int> numAssertsCurrentTest_atomic;
      AtomicOrMultiLaneAtomic<int> numAssertsFailedCurrentTest_atomic;

      std::vector<std::vector<String>> filters = decltype(filters)(9);// 9 different filters

      std::vector<IReporter *> reporters_currently_used;

      assert_handler ah = nullptr;

      Timer timer;

      std::vector<String> stringifiedContexts;// logging from INFO() due to an exception

      // stuff for subcases
      std::vector<SubcaseSignature> subcasesStack;
      std::set<decltype(subcasesStack)> subcasesPassed;
      int subcasesCurrentMaxLevel;
      bool should_reenter;
      std::atomic<bool> shouldLogCurrentException;

      void resetRunData() {
        numTestCases = 0;
        numTestCasesPassingFilters = 0;
        numTestSuitesPassingFilters = 0;
        numTestCasesFailed = 0;
        numAsserts = 0;
        numAssertsFailed = 0;
        numAssertsCurrentTest = 0;
        numAssertsFailedCurrentTest = 0;
      }

      void finalizeTestCaseData() {
        seconds = timer.getElapsedSeconds();

        // update the non-atomic counters
        numAsserts += numAssertsCurrentTest_atomic;
        numAssertsFailed += numAssertsFailedCurrentTest_atomic;
        numAssertsCurrentTest = numAssertsCurrentTest_atomic;
        numAssertsFailedCurrentTest = numAssertsFailedCurrentTest_atomic;

        if (numAssertsFailedCurrentTest)
          failure_flags |= TestCaseFailureReason::AssertFailure;

        if (Approx(currentTest->m_timeout).epsilon(DBL_EPSILON) != 0 &&
            Approx(seconds).epsilon(DBL_EPSILON) > currentTest->m_timeout)
          failure_flags |= TestCaseFailureReason::Timeout;

        if (currentTest->m_should_fail) {
          if (failure_flags) {
            failure_flags |= TestCaseFailureReason::ShouldHaveFailedAndDid;
          } else {
            failure_flags |= TestCaseFailureReason::ShouldHaveFailedButDidnt;
          }
        } else if (failure_flags && currentTest->m_may_fail) {
          failure_flags |= TestCaseFailureReason::CouldHaveFailedAndDid;
        } else if (currentTest->m_expected_failures > 0) {
          if (numAssertsFailedCurrentTest == currentTest->m_expected_failures) {
            failure_flags |= TestCaseFailureReason::FailedExactlyNumTimes;
          } else {
            failure_flags |= TestCaseFailureReason::DidntFailExactlyNumTimes;
          }
        }

        bool ok_to_fail = (TestCaseFailureReason::ShouldHaveFailedAndDid & failure_flags) ||
                          (TestCaseFailureReason::CouldHaveFailedAndDid & failure_flags) ||
                          (TestCaseFailureReason::FailedExactlyNumTimes & failure_flags);

        // if any subcase has failed - the whole test case has failed
        testCaseSuccess = !(failure_flags && !ok_to_fail);
        if (!testCaseSuccess)
          numTestCasesFailed++;
      }
    };

    ContextState *g_cs = nullptr;

    // used to avoid locks for the debug output
    // TODO: figure out if this is indeed necessary/correct - seems like either there still
    // could be a race or that there wouldn't be a race even if using the context directly
    DOCTEST_THREAD_LOCAL bool g_no_colors;

#endif// DOCTEST_CONFIG_DISABLE
  }   // namespace detail

  char *String::allocate(unsigned sz) {
    if (sz <= last) {
      buf[sz] = '\0';
      setLast(last - sz);
      return buf;
    } else {
      setOnHeap();
      data.size = sz;
      data.capacity = data.size + 1;
      data.ptr = new char[data.capacity];
      data.ptr[sz] = '\0';
      return data.ptr;
    }
  }

  void String::setOnHeap() { *reinterpret_cast<unsigned char *>(&buf[last]) = 128; }
  void String::setLast(unsigned in) { buf[last] = char(in); }

  void String::copy(const String &other) {
    if (other.isOnStack()) {
      memcpy(buf, other.buf, len);
    } else {
      memcpy(allocate(other.data.size), other.data.ptr, other.data.size);
    }
  }

  String::String() {
    buf[0] = '\0';
    setLast();
  }

  String::~String() {
    if (!isOnStack())
      delete[] data.ptr;
    // NOLINTNEXTLINE(clang-analyzer-cplusplus.NewDeleteLeaks)
  }

  String::String(const char *in)
      : String(in, strlen(in)) {}

  String::String(const char *in, unsigned in_size) {
    memcpy(allocate(in_size), in, in_size);
  }

  String::String(std::istream &in, unsigned in_size) {
    in.read(allocate(in_size), in_size);
  }

  String::String(const String &other) { copy(other); }

  String &String::operator=(const String &other) {
    if (this != &other) {
      if (!isOnStack())
        delete[] data.ptr;

      copy(other);
    }

    return *this;
  }

  String &String::operator+=(const String &other) {
    const unsigned my_old_size = size();
    const unsigned other_size = other.size();
    const unsigned total_size = my_old_size + other_size;
    if (isOnStack()) {
      if (total_size < len) {
        // append to the current stack space
        memcpy(buf + my_old_size, other.c_str(), other_size + 1);
        // NOLINTNEXTLINE(clang-analyzer-cplusplus.NewDeleteLeaks)
        setLast(last - total_size);
      } else {
        // alloc new chunk
        char *temp = new char[total_size + 1];
        // copy current data to new location before writing in the union
        memcpy(temp, buf, my_old_size);// skip the +1 ('\0') for speed
        // update data in union
        setOnHeap();
        data.size = total_size;
        data.capacity = data.size + 1;
        data.ptr = temp;
        // transfer the rest of the data
        memcpy(data.ptr + my_old_size, other.c_str(), other_size + 1);
      }
    } else {
      if (data.capacity > total_size) {
        // append to the current heap block
        data.size = total_size;
        memcpy(data.ptr + my_old_size, other.c_str(), other_size + 1);
      } else {
        // resize
        data.capacity *= 2;
        if (data.capacity <= total_size)
          data.capacity = total_size + 1;
        // alloc new chunk
        char *temp = new char[data.capacity];
        // copy current data to new location before releasing it
        memcpy(temp, data.ptr, my_old_size);// skip the +1 ('\0') for speed
        // release old chunk
        delete[] data.ptr;
        // update the rest of the union members
        data.size = total_size;
        data.ptr = temp;
        // transfer the rest of the data
        memcpy(data.ptr + my_old_size, other.c_str(), other_size + 1);
      }
    }

    return *this;
  }

  String::String(String &&other) {
    memcpy(buf, other.buf, len);
    other.buf[0] = '\0';
    other.setLast();
  }

  String &String::operator=(String &&other) {
    if (this != &other) {
      if (!isOnStack())
        delete[] data.ptr;
      memcpy(buf, other.buf, len);
      other.buf[0] = '\0';
      other.setLast();
    }
    return *this;
  }

  char String::operator[](unsigned i) const {
    return const_cast<String *>(this)->operator[](i);// NOLINT
  }

  char &String::operator[](unsigned i) {
    if (isOnStack())
      return reinterpret_cast<char *>(buf)[i];
    return data.ptr[i];
  }

  DOCTEST_GCC_SUPPRESS_WARNING_WITH_PUSH("-Wmaybe-uninitialized")
  unsigned String::size() const {
    if (isOnStack())
      return last - (unsigned(buf[last]) & 31);// using "last" would work only if "len" is 32
    return data.size;
  }
  DOCTEST_GCC_SUPPRESS_WARNING_POP

  unsigned String::capacity() const {
    if (isOnStack())
      return len;
    return data.capacity;
  }

  int String::compare(const char *other, bool no_case) const {
    if (no_case)
      return doctest::stricmp(c_str(), other);
    return std::strcmp(c_str(), other);
  }

  int String::compare(const String &other, bool no_case) const {
    return compare(other.c_str(), no_case);
  }

  // NOLINTNEXTLINE(clang-analyzer-cplusplus.NewDeleteLeaks)
  String operator+(const String &lhs, const String &rhs) { return String(lhs) += rhs; }

  // clang-format off
bool operator==(const String& lhs, const String& rhs) { return lhs.compare(rhs) == 0; }
bool operator!=(const String& lhs, const String& rhs) { return lhs.compare(rhs) != 0; }
bool operator< (const String& lhs, const String& rhs) { return lhs.compare(rhs) < 0; }
bool operator> (const String& lhs, const String& rhs) { return lhs.compare(rhs) > 0; }
bool operator<=(const String& lhs, const String& rhs) { return (lhs != rhs) ? lhs.compare(rhs) < 0 : true; }
bool operator>=(const String& lhs, const String& rhs) { return (lhs != rhs) ? lhs.compare(rhs) > 0 : true; }
  // clang-format on

  std::ostream &operator<<(std::ostream &s, const String &in) { return s << in.c_str(); }

  namespace {
    void color_to_stream(std::ostream &, Color::Enum) DOCTEST_BRANCH_ON_DISABLED({}, ;)
  }// namespace

  namespace Color {
    std::ostream &operator<<(std::ostream &s, Color::Enum code) {
      color_to_stream(s, code);
      return s;
    }
  }// namespace Color

  // clang-format off
const char* assertString(assertType::Enum at) {
    DOCTEST_MSVC_SUPPRESS_WARNING_WITH_PUSH(4062) // enum 'x' in switch of enum 'y' is not handled
    switch(at) {  //!OCLINT missing default in switch statements
        case assertType::DT_WARN                    : return "WARN";
        case assertType::DT_CHECK                   : return "CHECK";
        case assertType::DT_REQUIRE                 : return "REQUIRE";

        case assertType::DT_WARN_FALSE              : return "WARN_FALSE";
        case assertType::DT_CHECK_FALSE             : return "CHECK_FALSE";
        case assertType::DT_REQUIRE_FALSE           : return "REQUIRE_FALSE";

        case assertType::DT_WARN_THROWS             : return "WARN_THROWS";
        case assertType::DT_CHECK_THROWS            : return "CHECK_THROWS";
        case assertType::DT_REQUIRE_THROWS          : return "REQUIRE_THROWS";

        case assertType::DT_WARN_THROWS_AS          : return "WARN_THROWS_AS";
        case assertType::DT_CHECK_THROWS_AS         : return "CHECK_THROWS_AS";
        case assertType::DT_REQUIRE_THROWS_AS       : return "REQUIRE_THROWS_AS";

        case assertType::DT_WARN_THROWS_WITH        : return "WARN_THROWS_WITH";
        case assertType::DT_CHECK_THROWS_WITH       : return "CHECK_THROWS_WITH";
        case assertType::DT_REQUIRE_THROWS_WITH     : return "REQUIRE_THROWS_WITH";

        case assertType::DT_WARN_THROWS_WITH_AS     : return "WARN_THROWS_WITH_AS";
        case assertType::DT_CHECK_THROWS_WITH_AS    : return "CHECK_THROWS_WITH_AS";
        case assertType::DT_REQUIRE_THROWS_WITH_AS  : return "REQUIRE_THROWS_WITH_AS";

        case assertType::DT_WARN_NOTHROW            : return "WARN_NOTHROW";
        case assertType::DT_CHECK_NOTHROW           : return "CHECK_NOTHROW";
        case assertType::DT_REQUIRE_NOTHROW         : return "REQUIRE_NOTHROW";

        case assertType::DT_WARN_EQ                 : return "WARN_EQ";
        case assertType::DT_CHECK_EQ                : return "CHECK_EQ";
        case assertType::DT_REQUIRE_EQ              : return "REQUIRE_EQ";
        case assertType::DT_WARN_NE                 : return "WARN_NE";
        case assertType::DT_CHECK_NE                : return "CHECK_NE";
        case assertType::DT_REQUIRE_NE              : return "REQUIRE_NE";
        case assertType::DT_WARN_GT                 : return "WARN_GT";
        case assertType::DT_CHECK_GT                : return "CHECK_GT";
        case assertType::DT_REQUIRE_GT              : return "REQUIRE_GT";
        case assertType::DT_WARN_LT                 : return "WARN_LT";
        case assertType::DT_CHECK_LT                : return "CHECK_LT";
        case assertType::DT_REQUIRE_LT              : return "REQUIRE_LT";
        case assertType::DT_WARN_GE                 : return "WARN_GE";
        case assertType::DT_CHECK_GE                : return "CHECK_GE";
        case assertType::DT_REQUIRE_GE              : return "REQUIRE_GE";
        case assertType::DT_WARN_LE                 : return "WARN_LE";
        case assertType::DT_CHECK_LE                : return "CHECK_LE";
        case assertType::DT_REQUIRE_LE              : return "REQUIRE_LE";

        case assertType::DT_WARN_UNARY              : return "WARN_UNARY";
        case assertType::DT_CHECK_UNARY             : return "CHECK_UNARY";
        case assertType::DT_REQUIRE_UNARY           : return "REQUIRE_UNARY";
        case assertType::DT_WARN_UNARY_FALSE        : return "WARN_UNARY_FALSE";
        case assertType::DT_CHECK_UNARY_FALSE       : return "CHECK_UNARY_FALSE";
        case assertType::DT_REQUIRE_UNARY_FALSE     : return "REQUIRE_UNARY_FALSE";
    }
    DOCTEST_MSVC_SUPPRESS_WARNING_POP
    return "";
}
  // clang-format on

  const char *failureString(assertType::Enum at) {
    if (at & assertType::is_warn)//!OCLINT bitwise operator in conditional
      return "WARNING";
    if (at & assertType::is_check)//!OCLINT bitwise operator in conditional
      return "ERROR";
    if (at & assertType::is_require)//!OCLINT bitwise operator in conditional
      return "FATAL ERROR";
    return "";
  }

  DOCTEST_CLANG_SUPPRESS_WARNING_WITH_PUSH("-Wnull-dereference")
  DOCTEST_GCC_SUPPRESS_WARNING_WITH_PUSH("-Wnull-dereference")
  // depending on the current options this will remove the path of filenames
  const char *skipPathFromFilename(const char *file) {
#ifndef DOCTEST_CONFIG_DISABLE
    if (getContextOptions()->no_path_in_filenames) {
      auto back = std::strrchr(file, '\\');
      auto forward = std::strrchr(file, '/');
      if (back || forward) {
        if (back > forward)
          forward = back;
        return forward + 1;
      }
    }
#endif// DOCTEST_CONFIG_DISABLE
    return file;
  }
  DOCTEST_CLANG_SUPPRESS_WARNING_POP
  DOCTEST_GCC_SUPPRESS_WARNING_POP

  bool SubcaseSignature::operator<(const SubcaseSignature &other) const {
    if (m_line != other.m_line)
      return m_line < other.m_line;
    if (std::strcmp(m_file, other.m_file) != 0)
      return std::strcmp(m_file, other.m_file) < 0;
    return m_name.compare(other.m_name) < 0;
  }

  IContextScope::IContextScope() = default;
  IContextScope::~IContextScope() = default;

#ifdef DOCTEST_CONFIG_TREAT_CHAR_STAR_AS_STRING
  String toString(char *in) { return toString(static_cast<const char *>(in)); }
  // NOLINTNEXTLINE(clang-analyzer-cplusplus.NewDeleteLeaks)
  String toString(const char *in) { return String("\"") + (in ? in : "{null string}") + "\""; }
#endif// DOCTEST_CONFIG_TREAT_CHAR_STAR_AS_STRING
  String toString(bool in) { return in ? "true" : "false"; }
  String toString(float in) { return fpToString(in, 5) + "f"; }
  String toString(double in) { return fpToString(in, 10); }
  String toString(double long in) { return fpToString(in, 15); }

#define DOCTEST_TO_STRING_OVERLOAD(type, fmt) \
  String toString(type in) {                  \
    char buf[64];                             \
    std::sprintf(buf, fmt, in);               \
    return buf;                               \
  }

  DOCTEST_TO_STRING_OVERLOAD(char, "%d")
  DOCTEST_TO_STRING_OVERLOAD(char signed, "%d")
  DOCTEST_TO_STRING_OVERLOAD(char unsigned, "%u")
  DOCTEST_TO_STRING_OVERLOAD(int short, "%d")
  DOCTEST_TO_STRING_OVERLOAD(int short unsigned, "%u")
  DOCTEST_TO_STRING_OVERLOAD(int, "%d")
  DOCTEST_TO_STRING_OVERLOAD(unsigned, "%u")
  DOCTEST_TO_STRING_OVERLOAD(int long, "%ld")
  DOCTEST_TO_STRING_OVERLOAD(int long unsigned, "%lu")
  DOCTEST_TO_STRING_OVERLOAD(int long long, "%lld")
  DOCTEST_TO_STRING_OVERLOAD(int long long unsigned, "%llu")

  String toString(std::nullptr_t) { return "NULL"; }

#if DOCTEST_MSVC >= DOCTEST_COMPILER(19, 20, 0)
  // see this issue on why this is needed: https://github.com/doctest/doctest/issues/183
  String toString(const std::string &in) { return in.c_str(); }
#endif// VS 2019

  Approx::Approx(double value)
      : m_epsilon(static_cast<double>(std::numeric_limits<float>::epsilon()) * 100), m_scale(1.0), m_value(value) {}

  Approx Approx::operator()(double value) const {
    Approx approx(value);
    approx.epsilon(m_epsilon);
    approx.scale(m_scale);
    return approx;
  }

  Approx &Approx::epsilon(double newEpsilon) {
    m_epsilon = newEpsilon;
    return *this;
  }
  Approx &Approx::scale(double newScale) {
    m_scale = newScale;
    return *this;
  }

  bool operator==(double lhs, const Approx &rhs) {
    // Thanks to Richard Harris for his help refining this formula
    return std::fabs(lhs - rhs.m_value) <
           rhs.m_epsilon * (rhs.m_scale + std::max<double>(std::fabs(lhs), std::fabs(rhs.m_value)));
  }
  bool operator==(const Approx &lhs, double rhs) { return operator==(rhs, lhs); }
  bool operator!=(double lhs, const Approx &rhs) { return !operator==(lhs, rhs); }
  bool operator!=(const Approx &lhs, double rhs) { return !operator==(rhs, lhs); }
  bool operator<=(double lhs, const Approx &rhs) { return lhs < rhs.m_value || lhs == rhs; }
  bool operator<=(const Approx &lhs, double rhs) { return lhs.m_value < rhs || lhs == rhs; }
  bool operator>=(double lhs, const Approx &rhs) { return lhs > rhs.m_value || lhs == rhs; }
  bool operator>=(const Approx &lhs, double rhs) { return lhs.m_value > rhs || lhs == rhs; }
  bool operator<(double lhs, const Approx &rhs) { return lhs < rhs.m_value && lhs != rhs; }
  bool operator<(const Approx &lhs, double rhs) { return lhs.m_value < rhs && lhs != rhs; }
  bool operator>(double lhs, const Approx &rhs) { return lhs > rhs.m_value && lhs != rhs; }
  bool operator>(const Approx &lhs, double rhs) { return lhs.m_value > rhs && lhs != rhs; }

  String toString(const Approx &in) {
    // NOLINTNEXTLINE(clang-analyzer-cplusplus.NewDeleteLeaks)
    return "Approx( " + doctest::toString(in.m_value) + " )";
  }
  const ContextOptions *getContextOptions() { return DOCTEST_BRANCH_ON_DISABLED(nullptr, g_cs); }

}// namespace doctest

#ifdef DOCTEST_CONFIG_DISABLE
namespace doctest {
  Context::Context(int, const char *const *) {}
  Context::~Context() = default;
  void Context::applyCommandLine(int, const char *const *) {}
  void Context::addFilter(const char *, const char *) {}
  void Context::clearFilters() {}
  void Context::setOption(const char *, bool) {}
  void Context::setOption(const char *, int) {}
  void Context::setOption(const char *, const char *) {}
  bool Context::shouldExit() { return false; }
  void Context::setAsDefaultForAssertsOutOfTestCases() {}
  void Context::setAssertHandler(detail::assert_handler) {}
  void Context::setCout(std::ostream *out) {}
  int Context::run() { return 0; }

  IReporter::~IReporter() = default;

  int IReporter::get_num_active_contexts() { return 0; }
  const IContextScope *const *IReporter::get_active_contexts() { return nullptr; }
  int IReporter::get_num_stringified_contexts() { return 0; }
  const String *IReporter::get_stringified_contexts() { return nullptr; }

  int registerReporter(const char *, int, IReporter *) { return 0; }

}// namespace doctest
#else// DOCTEST_CONFIG_DISABLE

#if !defined(DOCTEST_CONFIG_COLORS_NONE)
#if !defined(DOCTEST_CONFIG_COLORS_WINDOWS) && !defined(DOCTEST_CONFIG_COLORS_ANSI)
#ifdef DOCTEST_PLATFORM_WINDOWS
#define DOCTEST_CONFIG_COLORS_WINDOWS
#else// linux
#define DOCTEST_CONFIG_COLORS_ANSI
#endif// platform
#endif// DOCTEST_CONFIG_COLORS_WINDOWS && DOCTEST_CONFIG_COLORS_ANSI
#endif// DOCTEST_CONFIG_COLORS_NONE

namespace doctest_detail_test_suite_ns {
  // holds the current test suite
  doctest::detail::TestSuite &getCurrentTestSuite() {
    static doctest::detail::TestSuite data{};
    return data;
  }
}// namespace doctest_detail_test_suite_ns

namespace doctest {
  namespace {
    // the int (priority) is part of the key for automatic sorting - sadly one can register a
    // reporter with a duplicate name and a different priority but hopefully that won't happen often :|
    typedef std::map<std::pair<int, String>, reporterCreatorFunc> reporterMap;

    reporterMap &getReporters() {
      static reporterMap data;
      return data;
    }
    reporterMap &getListeners() {
      static reporterMap data;
      return data;
    }
  }// namespace
  namespace detail {
#define DOCTEST_ITERATE_THROUGH_REPORTERS(function, ...) \
  for (auto &curr_rep: g_cs->reporters_currently_used)   \
  curr_rep->function(__VA_ARGS__)

    bool checkIfShouldThrow(assertType::Enum at) {
      if (at & assertType::is_require)//!OCLINT bitwise operator in conditional
        return true;

      if ((at & assertType::is_check)//!OCLINT bitwise operator in conditional
          && getContextOptions()->abort_after > 0 &&
          (g_cs->numAssertsFailed + g_cs->numAssertsFailedCurrentTest_atomic) >=
                  getContextOptions()->abort_after)
        return true;

      return false;
    }

#ifndef DOCTEST_CONFIG_NO_EXCEPTIONS
    DOCTEST_NORETURN void throwException() {
      g_cs->shouldLogCurrentException = false;
      throw TestFailureException();
    }// NOLINT(cert-err60-cpp)
#else // DOCTEST_CONFIG_NO_EXCEPTIONS
    void throwException() {}
#endif// DOCTEST_CONFIG_NO_EXCEPTIONS
  }  // namespace detail

  namespace {
    using namespace detail;
    // matching of a string against a wildcard mask (case sensitivity configurable) taken from
    // https://www.codeproject.com/Articles/1088/Wildcard-string-compare-globbing
    int wildcmp(const char *str, const char *wild, bool caseSensitive) {
      const char *cp = str;
      const char *mp = wild;

      while ((*str) && (*wild != '*')) {
        if ((caseSensitive ? (*wild != *str) : (tolower(*wild) != tolower(*str))) &&
            (*wild != '?')) {
          return 0;
        }
        wild++;
        str++;
      }

      while (*str) {
        if (*wild == '*') {
          if (!*++wild) {
            return 1;
          }
          mp = wild;
          cp = str + 1;
        } else if ((caseSensitive ? (*wild == *str) : (tolower(*wild) == tolower(*str))) ||
                   (*wild == '?')) {
          wild++;
          str++;
        } else {
          wild = mp; //!OCLINT parameter reassignment
          str = cp++;//!OCLINT parameter reassignment
        }
      }

      while (*wild == '*') {
        wild++;
      }
      return !*wild;
    }

    //// C string hash function (djb2) - taken from http://www.cse.yorku.ca/~oz/hash.html
    //unsigned hashStr(unsigned const char* str) {
    //    unsigned long hash = 5381;
    //    char          c;
    //    while((c = *str++))
    //        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    //    return hash;
    //}

    // checks if the name matches any of the filters (and can be configured what to do when empty)
    bool matchesAny(const char *name, const std::vector<String> &filters, bool matchEmpty,
                    bool caseSensitive) {
      if (filters.empty() && matchEmpty)
        return true;
      for (auto &curr: filters)
        if (wildcmp(name, curr.c_str(), caseSensitive))
          return true;
      return false;
    }
  }// namespace
  namespace detail {

    Subcase::Subcase(const String &name, const char *file, int line)
        : m_signature({name, file, line}) {
      auto *s = g_cs;

      // check subcase filters
      if (s->subcasesStack.size() < size_t(s->subcase_filter_levels)) {
        if (!matchesAny(m_signature.m_name.c_str(), s->filters[6], true, s->case_sensitive))
          return;
        if (matchesAny(m_signature.m_name.c_str(), s->filters[7], false, s->case_sensitive))
          return;
      }

      // if a Subcase on the same level has already been entered
      if (s->subcasesStack.size() < size_t(s->subcasesCurrentMaxLevel)) {
        s->should_reenter = true;
        return;
      }

      // push the current signature to the stack so we can check if the
      // current stack + the current new subcase have been traversed
      s->subcasesStack.push_back(m_signature);
      if (s->subcasesPassed.count(s->subcasesStack) != 0) {
        // pop - revert to previous stack since we've already passed this
        s->subcasesStack.pop_back();
        return;
      }

      s->subcasesCurrentMaxLevel = s->subcasesStack.size();
      m_entered = true;

      DOCTEST_ITERATE_THROUGH_REPORTERS(subcase_start, m_signature);
    }

    DOCTEST_MSVC_SUPPRESS_WARNING_WITH_PUSH(4996)// std::uncaught_exception is deprecated in C++17
    DOCTEST_GCC_SUPPRESS_WARNING_WITH_PUSH("-Wdeprecated-declarations")
    DOCTEST_CLANG_SUPPRESS_WARNING_WITH_PUSH("-Wdeprecated-declarations")

    Subcase::~Subcase() {
      if (m_entered) {
        // only mark the subcase stack as passed if no subcases have been skipped
        if (g_cs->should_reenter == false)
          g_cs->subcasesPassed.insert(g_cs->subcasesStack);
        g_cs->subcasesStack.pop_back();

#if defined(__cpp_lib_uncaught_exceptions) && __cpp_lib_uncaught_exceptions >= 201411L && (!defined(__MAC_OS_X_VERSION_MIN_REQUIRED) || __MAC_OS_X_VERSION_MIN_REQUIRED >= 101200)
        if (std::uncaught_exceptions() > 0
#else
        if (std::uncaught_exception()
#endif
            && g_cs->shouldLogCurrentException) {
          DOCTEST_ITERATE_THROUGH_REPORTERS(
                  test_case_exception, {"exception thrown in subcase - will translate later "
                                        "when the whole test case has been exited (cannot "
                                        "translate while there is an active exception)",
                                        false});
          g_cs->shouldLogCurrentException = false;
        }
        DOCTEST_ITERATE_THROUGH_REPORTERS(subcase_end, DOCTEST_EMPTY);
      }
    }

    DOCTEST_CLANG_SUPPRESS_WARNING_POP
    DOCTEST_GCC_SUPPRESS_WARNING_POP
    DOCTEST_MSVC_SUPPRESS_WARNING_POP

    Subcase::operator bool() const { return m_entered; }

    Result::Result(bool passed, const String &decomposition)
        : m_passed(passed), m_decomp(decomposition) {}

    ExpressionDecomposer::ExpressionDecomposer(assertType::Enum at)
        : m_at(at) {}

    TestSuite &TestSuite::operator*(const char *in) {
      m_test_suite = in;
      return *this;
    }

    TestCase::TestCase(funcType test, const char *file, unsigned line, const TestSuite &test_suite,
                       const char *type, int template_id) {
      m_file = file;
      m_line = line;
      m_name = nullptr;// will be later overridden in operator*
      m_test_suite = test_suite.m_test_suite;
      m_description = test_suite.m_description;
      m_skip = test_suite.m_skip;
      m_no_breaks = test_suite.m_no_breaks;
      m_no_output = test_suite.m_no_output;
      m_may_fail = test_suite.m_may_fail;
      m_should_fail = test_suite.m_should_fail;
      m_expected_failures = test_suite.m_expected_failures;
      m_timeout = test_suite.m_timeout;

      m_test = test;
      m_type = type;
      m_template_id = template_id;
    }

    TestCase::TestCase(const TestCase &other)
        : TestCaseData() {
      *this = other;
    }

    DOCTEST_MSVC_SUPPRESS_WARNING_WITH_PUSH(26434)// hides a non-virtual function
    DOCTEST_MSVC_SUPPRESS_WARNING(26437)          // Do not slice
    TestCase &TestCase::operator=(const TestCase &other) {
      static_cast<TestCaseData &>(*this) = static_cast<const TestCaseData &>(other);

      m_test = other.m_test;
      m_type = other.m_type;
      m_template_id = other.m_template_id;
      m_full_name = other.m_full_name;

      if (m_template_id != -1)
        m_name = m_full_name.c_str();
      return *this;
    }
    DOCTEST_MSVC_SUPPRESS_WARNING_POP

    TestCase &TestCase::operator*(const char *in) {
      m_name = in;
      // make a new name with an appended type for templated test case
      if (m_template_id != -1) {
        m_full_name = String(m_name) + m_type;
        // redirect the name to point to the newly constructed full name
        m_name = m_full_name.c_str();
      }
      return *this;
    }

    bool TestCase::operator<(const TestCase &other) const {
      // this will be used only to differentiate between test cases - not relevant for sorting
      if (m_line != other.m_line)
        return m_line < other.m_line;
      const int name_cmp = strcmp(m_name, other.m_name);
      if (name_cmp != 0)
        return name_cmp < 0;
      const int file_cmp = m_file.compare(other.m_file);
      if (file_cmp != 0)
        return file_cmp < 0;
      return m_template_id < other.m_template_id;
    }

    // all the registered tests
    std::set<TestCase> &getRegisteredTests() {
      static std::set<TestCase> data;
      return data;
    }
  }// namespace detail
  namespace {
    using namespace detail;
    // for sorting tests by file/line
    bool fileOrderComparator(const TestCase *lhs, const TestCase *rhs) {
      // this is needed because MSVC gives different case for drive letters
      // for __FILE__ when evaluated in a header and a source file
      const int res = lhs->m_file.compare(rhs->m_file, bool(DOCTEST_MSVC));
      if (res != 0)
        return res < 0;
      if (lhs->m_line != rhs->m_line)
        return lhs->m_line < rhs->m_line;
      return lhs->m_template_id < rhs->m_template_id;
    }

    // for sorting tests by suite/file/line
    bool suiteOrderComparator(const TestCase *lhs, const TestCase *rhs) {
      const int res = std::strcmp(lhs->m_test_suite, rhs->m_test_suite);
      if (res != 0)
        return res < 0;
      return fileOrderComparator(lhs, rhs);
    }

    // for sorting tests by name/suite/file/line
    bool nameOrderComparator(const TestCase *lhs, const TestCase *rhs) {
      const int res = std::strcmp(lhs->m_name, rhs->m_name);
      if (res != 0)
        return res < 0;
      return suiteOrderComparator(lhs, rhs);
    }

    DOCTEST_CLANG_SUPPRESS_WARNING_WITH_PUSH("-Wdeprecated-declarations")
    void color_to_stream(std::ostream &s, Color::Enum code) {
      static_cast<void>(s);   // for DOCTEST_CONFIG_COLORS_NONE or DOCTEST_CONFIG_COLORS_WINDOWS
      static_cast<void>(code);// for DOCTEST_CONFIG_COLORS_NONE
#ifdef DOCTEST_CONFIG_COLORS_ANSI
      if (g_no_colors ||
          (isatty(STDOUT_FILENO) == false && getContextOptions()->force_colors == false))
        return;

      auto col = "";
      // clang-format off
            switch(code) { //!OCLINT missing break in switch statement / unnecessary default statement in covered switch statement
                case Color::Red:         col = "[0;31m"; break;
                case Color::Green:       col = "[0;32m"; break;
                case Color::Blue:        col = "[0;34m"; break;
                case Color::Cyan:        col = "[0;36m"; break;
                case Color::Yellow:      col = "[0;33m"; break;
                case Color::Grey:        col = "[1;30m"; break;
                case Color::LightGrey:   col = "[0;37m"; break;
                case Color::BrightRed:   col = "[1;31m"; break;
                case Color::BrightGreen: col = "[1;32m"; break;
                case Color::BrightWhite: col = "[1;37m"; break;
                case Color::Bright: // invalid
                case Color::None:
                case Color::White:
                default:                 col = "[0m";
            }
      // clang-format on
      s << "\033" << col;
#endif// DOCTEST_CONFIG_COLORS_ANSI

#ifdef DOCTEST_CONFIG_COLORS_WINDOWS
      if (g_no_colors ||
          (_isatty(_fileno(stdout)) == false && getContextOptions()->force_colors == false))
        return;

      static struct ConsoleHelper {
        HANDLE stdoutHandle;
        WORD origFgAttrs;
        WORD origBgAttrs;

        ConsoleHelper() {
          stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
          CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
          GetConsoleScreenBufferInfo(stdoutHandle, &csbiInfo);
          origFgAttrs = csbiInfo.wAttributes & ~(BACKGROUND_GREEN | BACKGROUND_RED |
                                                 BACKGROUND_BLUE | BACKGROUND_INTENSITY);
          origBgAttrs = csbiInfo.wAttributes & ~(FOREGROUND_GREEN | FOREGROUND_RED |
                                                 FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        }
      } ch;

#define DOCTEST_SET_ATTR(x) SetConsoleTextAttribute(ch.stdoutHandle, x | ch.origBgAttrs)

      // clang-format off
        switch (code) {
            case Color::White:       DOCTEST_SET_ATTR(FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE); break;
            case Color::Red:         DOCTEST_SET_ATTR(FOREGROUND_RED);                                      break;
            case Color::Green:       DOCTEST_SET_ATTR(FOREGROUND_GREEN);                                    break;
            case Color::Blue:        DOCTEST_SET_ATTR(FOREGROUND_BLUE);                                     break;
            case Color::Cyan:        DOCTEST_SET_ATTR(FOREGROUND_BLUE | FOREGROUND_GREEN);                  break;
            case Color::Yellow:      DOCTEST_SET_ATTR(FOREGROUND_RED | FOREGROUND_GREEN);                   break;
            case Color::Grey:        DOCTEST_SET_ATTR(0);                                                   break;
            case Color::LightGrey:   DOCTEST_SET_ATTR(FOREGROUND_INTENSITY);                                break;
            case Color::BrightRed:   DOCTEST_SET_ATTR(FOREGROUND_INTENSITY | FOREGROUND_RED);               break;
            case Color::BrightGreen: DOCTEST_SET_ATTR(FOREGROUND_INTENSITY | FOREGROUND_GREEN);             break;
            case Color::BrightWhite: DOCTEST_SET_ATTR(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE); break;
            case Color::None:
            case Color::Bright: // invalid
            default:                 DOCTEST_SET_ATTR(ch.origFgAttrs);
        }
        // clang-format on
#endif// DOCTEST_CONFIG_COLORS_WINDOWS
    }
    DOCTEST_CLANG_SUPPRESS_WARNING_POP

    std::vector<const IExceptionTranslator *> &getExceptionTranslators() {
      static std::vector<const IExceptionTranslator *> data;
      return data;
    }

    String translateActiveException() {
#ifndef DOCTEST_CONFIG_NO_EXCEPTIONS
      String res;
      auto &translators = getExceptionTranslators();
      for (auto &curr: translators)
        if (curr->translate(res))
          return res;
      // clang-format off
        DOCTEST_GCC_SUPPRESS_WARNING_WITH_PUSH("-Wcatch-value")
        try {
            throw;
        } catch(std::exception& ex) {
            return ex.what();
        } catch(std::string& msg) {
            return msg.c_str();
        } catch(const char* msg) {
            return msg;
        } catch(...) {
            return "unknown exception";
        }
        DOCTEST_GCC_SUPPRESS_WARNING_POP
// clang-format on
#else // DOCTEST_CONFIG_NO_EXCEPTIONS
      return "";
#endif// DOCTEST_CONFIG_NO_EXCEPTIONS
    }
  }// namespace

  namespace detail {
    // used by the macros for registering tests
    int regTest(const TestCase &tc) {
      getRegisteredTests().insert(tc);
      return 0;
    }

    // sets the current test suite
    int setTestSuite(const TestSuite &ts) {
      doctest_detail_test_suite_ns::getCurrentTestSuite() = ts;
      return 0;
    }

#ifdef DOCTEST_IS_DEBUGGER_ACTIVE
    bool isDebuggerActive() { return DOCTEST_IS_DEBUGGER_ACTIVE(); }
#else// DOCTEST_IS_DEBUGGER_ACTIVE
#ifdef DOCTEST_PLATFORM_LINUX
    class ErrnoGuard {
  public:
      ErrnoGuard() : m_oldErrno(errno) {}
      ~ErrnoGuard() { errno = m_oldErrno; }

  private:
      int m_oldErrno;
    };
    // See the comments in Catch2 for the reasoning behind this implementation:
    // https://github.com/catchorg/Catch2/blob/v2.13.1/include/internal/catch_debugger.cpp#L79-L102
    bool isDebuggerActive() {
      ErrnoGuard guard;
      std::ifstream in("/proc/self/status");
      for (std::string line; std::getline(in, line);) {
        static const int PREFIX_LEN = 11;
        if (line.compare(0, PREFIX_LEN, "TracerPid:\t") == 0) {
          return line.length() > PREFIX_LEN && line[PREFIX_LEN] != '0';
        }
      }
      return false;
    }
#elif defined(DOCTEST_PLATFORM_MAC)
    // The following function is taken directly from the following technical note:
    // https://developer.apple.com/library/archive/qa/qa1361/_index.html
    // Returns true if the current process is being debugged (either
    // running under the debugger or has a debugger attached post facto).
    bool isDebuggerActive() {
      int mib[4];
      kinfo_proc info;
      size_t size;
      // Initialize the flags so that, if sysctl fails for some bizarre
      // reason, we get a predictable result.
      info.kp_proc.p_flag = 0;
      // Initialize mib, which tells sysctl the info we want, in this case
      // we're looking for information about a specific process ID.
      mib[0] = CTL_KERN;
      mib[1] = KERN_PROC;
      mib[2] = KERN_PROC_PID;
      mib[3] = getpid();
      // Call sysctl.
      size = sizeof(info);
      if (sysctl(mib, DOCTEST_COUNTOF(mib), &info, &size, 0, 0) != 0) {
        std::cerr << "\nCall to sysctl failed - unable to determine if debugger is active **\n";
        return false;
      }
      // We're being debugged if the P_TRACED flag is set.
      return ((info.kp_proc.p_flag & P_TRACED) != 0);
    }
#elif DOCTEST_MSVC || defined(__MINGW32__) || defined(__MINGW64__)
    bool isDebuggerActive() { return ::IsDebuggerPresent() != 0; }
#else
    bool isDebuggerActive() { return false; }
#endif// Platform
#endif// DOCTEST_IS_DEBUGGER_ACTIVE

    void registerExceptionTranslatorImpl(const IExceptionTranslator *et) {
      if (std::find(getExceptionTranslators().begin(), getExceptionTranslators().end(), et) ==
          getExceptionTranslators().end())
        getExceptionTranslators().push_back(et);
    }

#ifdef DOCTEST_CONFIG_TREAT_CHAR_STAR_AS_STRING
    void toStream(std::ostream *s, char *in) { *s << in; }
    void toStream(std::ostream *s, const char *in) { *s << in; }
#endif// DOCTEST_CONFIG_TREAT_CHAR_STAR_AS_STRING
    void toStream(std::ostream *s, bool in) { *s << std::boolalpha << in << std::noboolalpha; }
    void toStream(std::ostream *s, float in) { *s << in; }
    void toStream(std::ostream *s, double in) { *s << in; }
    void toStream(std::ostream *s, double long in) { *s << in; }

    void toStream(std::ostream *s, char in) { *s << in; }
    void toStream(std::ostream *s, char signed in) { *s << in; }
    void toStream(std::ostream *s, char unsigned in) { *s << in; }
    void toStream(std::ostream *s, int short in) { *s << in; }
    void toStream(std::ostream *s, int short unsigned in) { *s << in; }
    void toStream(std::ostream *s, int in) { *s << in; }
    void toStream(std::ostream *s, int unsigned in) { *s << in; }
    void toStream(std::ostream *s, int long in) { *s << in; }
    void toStream(std::ostream *s, int long unsigned in) { *s << in; }
    void toStream(std::ostream *s, int long long in) { *s << in; }
    void toStream(std::ostream *s, int long long unsigned in) { *s << in; }

    DOCTEST_THREAD_LOCAL std::vector<IContextScope *> g_infoContexts;// for logging with INFO()

    ContextScopeBase::ContextScopeBase() {
      g_infoContexts.push_back(this);
    }

    ContextScopeBase::ContextScopeBase(ContextScopeBase &&other) {
      if (other.need_to_destroy) {
        other.destroy();
      }
      other.need_to_destroy = false;
      g_infoContexts.push_back(this);
    }

    DOCTEST_MSVC_SUPPRESS_WARNING_WITH_PUSH(4996)// std::uncaught_exception is deprecated in C++17
    DOCTEST_GCC_SUPPRESS_WARNING_WITH_PUSH("-Wdeprecated-declarations")
    DOCTEST_CLANG_SUPPRESS_WARNING_WITH_PUSH("-Wdeprecated-declarations")

    // destroy cannot be inlined into the destructor because that would mean calling stringify after
    // ContextScope has been destroyed (base class destructors run after derived class destructors).
    // Instead, ContextScope calls this method directly from its destructor.
    void ContextScopeBase::destroy() {
#if defined(__cpp_lib_uncaught_exceptions) && __cpp_lib_uncaught_exceptions >= 201411L && (!defined(__MAC_OS_X_VERSION_MIN_REQUIRED) || __MAC_OS_X_VERSION_MIN_REQUIRED >= 101200)
      if (std::uncaught_exceptions() > 0) {
#else
      if (std::uncaught_exception()) {
#endif
        std::ostringstream s;
        this->stringify(&s);
        g_cs->stringifiedContexts.push_back(s.str().c_str());
      }
      g_infoContexts.pop_back();
    }

    DOCTEST_CLANG_SUPPRESS_WARNING_POP
    DOCTEST_GCC_SUPPRESS_WARNING_POP
    DOCTEST_MSVC_SUPPRESS_WARNING_POP
  }// namespace detail
  namespace {
    using namespace detail;

#if !defined(DOCTEST_CONFIG_POSIX_SIGNALS) && !defined(DOCTEST_CONFIG_WINDOWS_SEH)
    struct FatalConditionHandler {
      static void reset() {}
      static void allocateAltStackMem() {}
      static void freeAltStackMem() {}
    };
#else// DOCTEST_CONFIG_POSIX_SIGNALS || DOCTEST_CONFIG_WINDOWS_SEH

    void reportFatal(const std::string &);

#ifdef DOCTEST_PLATFORM_WINDOWS

    struct SignalDefs {
      DWORD id;
      const char *name;
    };
    // There is no 1-1 mapping between signals and windows exceptions.
    // Windows can easily distinguish between SO and SigSegV,
    // but SigInt, SigTerm, etc are handled differently.
    SignalDefs signalDefs[] = {
            {static_cast<DWORD>(EXCEPTION_ILLEGAL_INSTRUCTION),
             "SIGILL - Illegal instruction signal"},
            {static_cast<DWORD>(EXCEPTION_STACK_OVERFLOW), "SIGSEGV - Stack overflow"},
            {static_cast<DWORD>(EXCEPTION_ACCESS_VIOLATION),
             "SIGSEGV - Segmentation violation signal"},
            {static_cast<DWORD>(EXCEPTION_INT_DIVIDE_BY_ZERO), "Divide by zero error"},
    };

    struct FatalConditionHandler {
      static LONG CALLBACK handleException(PEXCEPTION_POINTERS ExceptionInfo) {
        // Multiple threads may enter this filter/handler at once. We want the error message to be printed on the
        // console just once no matter how many threads have crashed.
        static std::mutex mutex;
        static bool execute = true;
        {
          std::lock_guard<std::mutex> lock(mutex);
          if (execute) {
            bool reported = false;
            for (size_t i = 0; i < DOCTEST_COUNTOF(signalDefs); ++i) {
              if (ExceptionInfo->ExceptionRecord->ExceptionCode == signalDefs[i].id) {
                reportFatal(signalDefs[i].name);
                reported = true;
                break;
              }
            }
            if (reported == false)
              reportFatal("Unhandled SEH exception caught");
            if (isDebuggerActive() && !g_cs->no_breaks)
              DOCTEST_BREAK_INTO_DEBUGGER();
          }
          execute = false;
        }
        std::exit(EXIT_FAILURE);
      }

      static void allocateAltStackMem() {}
      static void freeAltStackMem() {}

      FatalConditionHandler() {
        isSet = true;
        // 32k seems enough for doctest to handle stack overflow,
        // but the value was found experimentally, so there is no strong guarantee
        guaranteeSize = 32 * 1024;
        // Register an unhandled exception filter
        previousTop = SetUnhandledExceptionFilter(handleException);
        // Pass in guarantee size to be filled
        SetThreadStackGuarantee(&guaranteeSize);

        // On Windows uncaught exceptions from another thread, exceptions from
        // destructors, or calls to std::terminate are not a SEH exception

        // The terminal handler gets called when:
        // - std::terminate is called FROM THE TEST RUNNER THREAD
        // - an exception is thrown from a destructor FROM THE TEST RUNNER THREAD
        original_terminate_handler = std::get_terminate();
        std::set_terminate([]() DOCTEST_NOEXCEPT {
          reportFatal("Terminate handler called");
          if (isDebuggerActive() && !g_cs->no_breaks)
            DOCTEST_BREAK_INTO_DEBUGGER();
          std::exit(EXIT_FAILURE);// explicitly exit - otherwise the SIGABRT handler may be called as well
        });

        // SIGABRT is raised when:
        // - std::terminate is called FROM A DIFFERENT THREAD
        // - an exception is thrown from a destructor FROM A DIFFERENT THREAD
        // - an uncaught exception is thrown FROM A DIFFERENT THREAD
        prev_sigabrt_handler = std::signal(SIGABRT, [](int signal) DOCTEST_NOEXCEPT {
          if (signal == SIGABRT) {
            reportFatal("SIGABRT - Abort (abnormal termination) signal");
            if (isDebuggerActive() && !g_cs->no_breaks)
              DOCTEST_BREAK_INTO_DEBUGGER();
            std::exit(EXIT_FAILURE);
          }
        });

        // The following settings are taken from google test, and more
        // specifically from UnitTest::Run() inside of gtest.cc

        // the user does not want to see pop-up dialogs about crashes
        prev_error_mode_1 = SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOALIGNMENTFAULTEXCEPT |
                                         SEM_NOGPFAULTERRORBOX | SEM_NOOPENFILEERRORBOX);
        // This forces the abort message to go to stderr in all circumstances.
        prev_error_mode_2 = _set_error_mode(_OUT_TO_STDERR);
        // In the debug version, Visual Studio pops up a separate dialog
        // offering a choice to debug the aborted program - we want to disable that.
        prev_abort_behavior = _set_abort_behavior(0x0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);
        // In debug mode, the Windows CRT can crash with an assertion over invalid
        // input (e.g. passing an invalid file descriptor). The default handling
        // for these assertions is to pop up a dialog and wait for user input.
        // Instead ask the CRT to dump such assertions to stderr non-interactively.
        prev_report_mode = _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG);
        prev_report_file = _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
      }

      static void reset() {
        if (isSet) {
          // Unregister handler and restore the old guarantee
          SetUnhandledExceptionFilter(previousTop);
          SetThreadStackGuarantee(&guaranteeSize);
          std::set_terminate(original_terminate_handler);
          std::signal(SIGABRT, prev_sigabrt_handler);
          SetErrorMode(prev_error_mode_1);
          _set_error_mode(prev_error_mode_2);
          _set_abort_behavior(prev_abort_behavior, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);
          static_cast<void>(_CrtSetReportMode(_CRT_ASSERT, prev_report_mode));
          static_cast<void>(_CrtSetReportFile(_CRT_ASSERT, prev_report_file));
          isSet = false;
        }
      }

      ~FatalConditionHandler() { reset(); }

  private:
      static UINT prev_error_mode_1;
      static int prev_error_mode_2;
      static unsigned int prev_abort_behavior;
      static int prev_report_mode;
      static _HFILE prev_report_file;
      static void(DOCTEST_CDECL *prev_sigabrt_handler)(int);
      static std::terminate_handler original_terminate_handler;
      static bool isSet;
      static ULONG guaranteeSize;
      static LPTOP_LEVEL_EXCEPTION_FILTER previousTop;
    };

    UINT FatalConditionHandler::prev_error_mode_1;
    int FatalConditionHandler::prev_error_mode_2;
    unsigned int FatalConditionHandler::prev_abort_behavior;
    int FatalConditionHandler::prev_report_mode;
    _HFILE FatalConditionHandler::prev_report_file;
    void(DOCTEST_CDECL *FatalConditionHandler::prev_sigabrt_handler)(int);
    std::terminate_handler FatalConditionHandler::original_terminate_handler;
    bool FatalConditionHandler::isSet = false;
    ULONG FatalConditionHandler::guaranteeSize = 0;
    LPTOP_LEVEL_EXCEPTION_FILTER FatalConditionHandler::previousTop = nullptr;

#else// DOCTEST_PLATFORM_WINDOWS

    struct SignalDefs {
      int id;
      const char *name;
    };
    SignalDefs signalDefs[] = {{SIGINT, "SIGINT - Terminal interrupt signal"},
                               {SIGILL, "SIGILL - Illegal instruction signal"},
                               {SIGFPE, "SIGFPE - Floating point error signal"},
                               {SIGSEGV, "SIGSEGV - Segmentation violation signal"},
                               {SIGTERM, "SIGTERM - Termination request signal"},
                               {SIGABRT, "SIGABRT - Abort (abnormal termination) signal"}};

    struct FatalConditionHandler {
      static bool isSet;
      static struct sigaction oldSigActions[DOCTEST_COUNTOF(signalDefs)];
      static stack_t oldSigStack;
      static size_t altStackSize;
      static char *altStackMem;

      static void handleSignal(int sig) {
        const char *name = "<unknown signal>";
        for (std::size_t i = 0; i < DOCTEST_COUNTOF(signalDefs); ++i) {
          SignalDefs &def = signalDefs[i];
          if (sig == def.id) {
            name = def.name;
            break;
          }
        }
        reset();
        reportFatal(name);
        raise(sig);
      }

      static void allocateAltStackMem() {
        altStackMem = new char[altStackSize];
      }

      static void freeAltStackMem() {
        delete[] altStackMem;
      }

      FatalConditionHandler() {
        isSet = true;
        stack_t sigStack;
        sigStack.ss_sp = altStackMem;
        sigStack.ss_size = altStackSize;
        sigStack.ss_flags = 0;
        sigaltstack(&sigStack, &oldSigStack);
        struct sigaction sa = {};
        sa.sa_handler = handleSignal;// NOLINT
        sa.sa_flags = SA_ONSTACK;
        for (std::size_t i = 0; i < DOCTEST_COUNTOF(signalDefs); ++i) {
          sigaction(signalDefs[i].id, &sa, &oldSigActions[i]);
        }
      }

      ~FatalConditionHandler() { reset(); }
      static void reset() {
        if (isSet) {
          // Set signals back to previous values -- hopefully nobody overwrote them in the meantime
          for (std::size_t i = 0; i < DOCTEST_COUNTOF(signalDefs); ++i) {
            sigaction(signalDefs[i].id, &oldSigActions[i], nullptr);
          }
          // Return the old stack
          sigaltstack(&oldSigStack, nullptr);
          isSet = false;
        }
      }
    };

    bool FatalConditionHandler::isSet = false;
    struct sigaction FatalConditionHandler::oldSigActions[DOCTEST_COUNTOF(signalDefs)] = {};
    stack_t FatalConditionHandler::oldSigStack = {};
    size_t FatalConditionHandler::altStackSize = 4 * SIGSTKSZ;
    char *FatalConditionHandler::altStackMem = nullptr;

#endif// DOCTEST_PLATFORM_WINDOWS
#endif// DOCTEST_CONFIG_POSIX_SIGNALS || DOCTEST_CONFIG_WINDOWS_SEH

  }// namespace

  namespace {
    using namespace detail;

#ifdef DOCTEST_PLATFORM_WINDOWS
#define DOCTEST_OUTPUT_DEBUG_STRING(text) ::OutputDebugStringA(text)
#else
    // TODO: integration with XCode and other IDEs
#define DOCTEST_OUTPUT_DEBUG_STRING(text)// NOLINT(clang-diagnostic-unused-macros)
#endif                                   // Platform

    void addAssert(assertType::Enum at) {
      if ((at & assertType::is_warn) == 0)//!OCLINT bitwise operator in conditional
        g_cs->numAssertsCurrentTest_atomic++;
    }

    void addFailedAssert(assertType::Enum at) {
      if ((at & assertType::is_warn) == 0)//!OCLINT bitwise operator in conditional
        g_cs->numAssertsFailedCurrentTest_atomic++;
    }

#if defined(DOCTEST_CONFIG_POSIX_SIGNALS) || defined(DOCTEST_CONFIG_WINDOWS_SEH)
    void reportFatal(const std::string &message) {
      g_cs->failure_flags |= TestCaseFailureReason::Crash;

      DOCTEST_ITERATE_THROUGH_REPORTERS(test_case_exception, {message.c_str(), true});

      while (g_cs->subcasesStack.size()) {
        g_cs->subcasesStack.pop_back();
        DOCTEST_ITERATE_THROUGH_REPORTERS(subcase_end, DOCTEST_EMPTY);
      }

      g_cs->finalizeTestCaseData();

      DOCTEST_ITERATE_THROUGH_REPORTERS(test_case_end, *g_cs);

      DOCTEST_ITERATE_THROUGH_REPORTERS(test_run_end, *g_cs);
    }
#endif// DOCTEST_CONFIG_POSIX_SIGNALS || DOCTEST_CONFIG_WINDOWS_SEH
  }// namespace
  namespace detail {

    ResultBuilder::ResultBuilder(assertType::Enum at, const char *file, int line, const char *expr,
                                 const char *exception_type, const char *exception_string) {
      m_test_case = g_cs->currentTest;
      m_at = at;
      m_file = file;
      m_line = line;
      m_expr = expr;
      m_failed = true;
      m_threw = false;
      m_threw_as = false;
      m_exception_type = exception_type;
      m_exception_string = exception_string;
#if DOCTEST_MSVC
      if (m_expr[0] == ' ')// this happens when variadic macros are disabled under MSVC
        ++m_expr;
#endif// MSVC
    }

    void ResultBuilder::setResult(const Result &res) {
      m_decomp = res.m_decomp;
      m_failed = !res.m_passed;
    }

    void ResultBuilder::translateException() {
      m_threw = true;
      m_exception = translateActiveException();
    }

    bool ResultBuilder::log() {
      if (m_at & assertType::is_throws) {//!OCLINT bitwise operator in conditional
        m_failed = !m_threw;
      } else if ((m_at & assertType::is_throws_as) && (m_at & assertType::is_throws_with)) {//!OCLINT
        m_failed = !m_threw_as || (m_exception != m_exception_string);
      } else if (m_at & assertType::is_throws_as) {//!OCLINT bitwise operator in conditional
        m_failed = !m_threw_as;
      } else if (m_at & assertType::is_throws_with) {//!OCLINT bitwise operator in conditional
        m_failed = m_exception != m_exception_string;
      } else if (m_at & assertType::is_nothrow) {//!OCLINT bitwise operator in conditional
        m_failed = m_threw;
      }

      if (m_exception.size())
        m_exception = "\"" + m_exception + "\"";

      if (is_running_in_test) {
        addAssert(m_at);
        DOCTEST_ITERATE_THROUGH_REPORTERS(log_assert, *this);

        if (m_failed)
          addFailedAssert(m_at);
      } else if (m_failed) {
        failed_out_of_a_testing_context(*this);
      }

      return m_failed && isDebuggerActive() && !getContextOptions()->no_breaks &&
             (g_cs->currentTest == nullptr || !g_cs->currentTest->m_no_breaks);// break into debugger
    }

    void ResultBuilder::react() const {
      if (m_failed && checkIfShouldThrow(m_at))
        throwException();
    }

    void failed_out_of_a_testing_context(const AssertData &ad) {
      if (g_cs->ah)
        g_cs->ah(ad);
      else
        std::abort();
    }

    bool decomp_assert(assertType::Enum at, const char *file, int line, const char *expr,
                       Result result) {
      bool failed = !result.m_passed;

      // ###################################################################################
      // IF THE DEBUGGER BREAKS HERE - GO 1 LEVEL UP IN THE CALLSTACK FOR THE FAILING ASSERT
      // THIS IS THE EFFECT OF HAVING 'DOCTEST_CONFIG_SUPER_FAST_ASSERTS' DEFINED
      // ###################################################################################
      DOCTEST_ASSERT_OUT_OF_TESTS(result.m_decomp);
      DOCTEST_ASSERT_IN_TESTS(result.m_decomp);
      // NOLINTNEXTLINE(clang-analyzer-cplusplus.NewDeleteLeaks)
      return !failed;
    }

    MessageBuilder::MessageBuilder(const char *file, int line, assertType::Enum severity) {
      m_stream = tlssPush();
      m_file = file;
      m_line = line;
      m_severity = severity;
    }

    MessageBuilder::~MessageBuilder() {
      if (!logged)
        tlssPop();
    }

    IExceptionTranslator::IExceptionTranslator() = default;
    IExceptionTranslator::~IExceptionTranslator() = default;

    bool MessageBuilder::log() {
      if (!logged) {
        m_string = tlssPop();
        logged = true;
      }

      DOCTEST_ITERATE_THROUGH_REPORTERS(log_message, *this);

      const bool isWarn = m_severity & assertType::is_warn;

      // warn is just a message in this context so we don't treat it as an assert
      if (!isWarn) {
        addAssert(m_severity);
        addFailedAssert(m_severity);
      }

      return isDebuggerActive() && !getContextOptions()->no_breaks && !isWarn &&
             (g_cs->currentTest == nullptr || !g_cs->currentTest->m_no_breaks);// break into debugger
    }

    void MessageBuilder::react() {
      if (m_severity & assertType::is_require)//!OCLINT bitwise operator in conditional
        throwException();
    }
  }// namespace detail
  namespace {
    using namespace detail;

    // clang-format off

// =================================================================================================
// The following code has been taken verbatim from Catch2/include/internal/catch_xmlwriter.h/cpp
// This is done so cherry-picking bug fixes is trivial - even the style/formatting is untouched.
// =================================================================================================

    class XmlEncode {
    public:
        enum ForWhat { ForTextNodes, ForAttributes };

        XmlEncode( std::string const& str, ForWhat forWhat = ForTextNodes );

        void encodeTo( std::ostream& os ) const;

        friend std::ostream& operator << ( std::ostream& os, XmlEncode const& xmlEncode );

    private:
        std::string m_str;
        ForWhat m_forWhat;
    };

    class XmlWriter {
    public:

        class ScopedElement {
        public:
            ScopedElement( XmlWriter* writer );

            ScopedElement( ScopedElement&& other ) DOCTEST_NOEXCEPT;
            ScopedElement& operator=( ScopedElement&& other ) DOCTEST_NOEXCEPT;

            ~ScopedElement();

            ScopedElement& writeText( std::string const& text, bool indent = true );

            template<typename T>
            ScopedElement& writeAttribute( std::string const& name, T const& attribute ) {
                m_writer->writeAttribute( name, attribute );
                return *this;
            }

        private:
            mutable XmlWriter* m_writer = nullptr;
        };

        XmlWriter( std::ostream& os = std::cout );
        ~XmlWriter();

        XmlWriter( XmlWriter const& ) = delete;
        XmlWriter& operator=( XmlWriter const& ) = delete;

        XmlWriter& startElement( std::string const& name );

        ScopedElement scopedElement( std::string const& name );

        XmlWriter& endElement();

        XmlWriter& writeAttribute( std::string const& name, std::string const& attribute );

        XmlWriter& writeAttribute( std::string const& name, const char* attribute );

        XmlWriter& writeAttribute( std::string const& name, bool attribute );

        template<typename T>
        XmlWriter& writeAttribute( std::string const& name, T const& attribute ) {
        std::stringstream rss;
            rss << attribute;
            return writeAttribute( name, rss.str() );
        }

        XmlWriter& writeText( std::string const& text, bool indent = true );

        //XmlWriter& writeComment( std::string const& text );

        //void writeStylesheetRef( std::string const& url );

        //XmlWriter& writeBlankLine();

        void ensureTagClosed();

    private:

        void writeDeclaration();

        void newlineIfNecessary();

        bool m_tagIsOpen = false;
        bool m_needsNewline = false;
        std::vector<std::string> m_tags;
        std::string m_indent;
        std::ostream& m_os;
    };

// =================================================================================================
// The following code has been taken verbatim from Catch2/include/internal/catch_xmlwriter.h/cpp
// This is done so cherry-picking bug fixes is trivial - even the style/formatting is untouched.
// =================================================================================================

using uchar = unsigned char;

namespace {

    size_t trailingBytes(unsigned char c) {
        if ((c & 0xE0) == 0xC0) {
            return 2;
        }
        if ((c & 0xF0) == 0xE0) {
            return 3;
        }
        if ((c & 0xF8) == 0xF0) {
            return 4;
        }
        DOCTEST_INTERNAL_ERROR("Invalid multibyte utf-8 start byte encountered");
    }

    uint32_t headerValue(unsigned char c) {
        if ((c & 0xE0) == 0xC0) {
            return c & 0x1F;
        }
        if ((c & 0xF0) == 0xE0) {
            return c & 0x0F;
        }
        if ((c & 0xF8) == 0xF0) {
            return c & 0x07;
        }
        DOCTEST_INTERNAL_ERROR("Invalid multibyte utf-8 start byte encountered");
    }

    void hexEscapeChar(std::ostream& os, unsigned char c) {
        std::ios_base::fmtflags f(os.flags());
        os << "\\x"
            << std::uppercase << std::hex << std::setfill('0') << std::setw(2)
            << static_cast<int>(c);
        os.flags(f);
    }

} // anonymous namespace

    XmlEncode::XmlEncode( std::string const& str, ForWhat forWhat )
    :   m_str( str ),
        m_forWhat( forWhat )
    {}

    void XmlEncode::encodeTo( std::ostream& os ) const {
        // Apostrophe escaping not necessary if we always use " to write attributes
        // (see: https://www.w3.org/TR/xml/#syntax)

        for( std::size_t idx = 0; idx < m_str.size(); ++ idx ) {
            uchar c = m_str[idx];
            switch (c) {
            case '<':   os << "&lt;"; break;
            case '&':   os << "&amp;"; break;

            case '>':
                // See: https://www.w3.org/TR/xml/#syntax
                if (idx > 2 && m_str[idx - 1] == ']' && m_str[idx - 2] == ']')
                    os << "&gt;";
                else
                    os << c;
                break;

            case '\"':
                if (m_forWhat == ForAttributes)
                    os << "&quot;";
                else
                    os << c;
                break;

            default:
                // Check for control characters and invalid utf-8

                // Escape control characters in standard ascii
                // see https://stackoverflow.com/questions/404107/why-are-control-characters-illegal-in-xml-1-0
                if (c < 0x09 || (c > 0x0D && c < 0x20) || c == 0x7F) {
                    hexEscapeChar(os, c);
                    break;
                }

                // Plain ASCII: Write it to stream
                if (c < 0x7F) {
                    os << c;
                    break;
                }

                // UTF-8 territory
                // Check if the encoding is valid and if it is not, hex escape bytes.
                // Important: We do not check the exact decoded values for validity, only the encoding format
                // First check that this bytes is a valid lead byte:
                // This means that it is not encoded as 1111 1XXX
                // Or as 10XX XXXX
                if (c <  0xC0 ||
                    c >= 0xF8) {
                    hexEscapeChar(os, c);
                    break;
                }

                auto encBytes = trailingBytes(c);
                // Are there enough bytes left to avoid accessing out-of-bounds memory?
                if (idx + encBytes - 1 >= m_str.size()) {
                    hexEscapeChar(os, c);
                    break;
                }
                // The header is valid, check data
                // The next encBytes bytes must together be a valid utf-8
                // This means: bitpattern 10XX XXXX and the extracted value is sane (ish)
                bool valid = true;
                uint32_t value = headerValue(c);
                for (std::size_t n = 1; n < encBytes; ++n) {
                    uchar nc = m_str[idx + n];
                    valid &= ((nc & 0xC0) == 0x80);
                    value = (value << 6) | (nc & 0x3F);
                }

                if (
                    // Wrong bit pattern of following bytes
                    (!valid) ||
                    // Overlong encodings
                    (value < 0x80) ||
                    (                 value < 0x800   && encBytes > 2) || // removed "0x80 <= value &&" because redundant
                    (0x800 < value && value < 0x10000 && encBytes > 3) ||
                    // Encoded value out of range
                    (value >= 0x110000)
                    ) {
                    hexEscapeChar(os, c);
                    break;
                }

                // If we got here, this is in fact a valid(ish) utf-8 sequence
                for (std::size_t n = 0; n < encBytes; ++n) {
                    os << m_str[idx + n];
                }
                idx += encBytes - 1;
                break;
            }
        }
    }

    std::ostream& operator << ( std::ostream& os, XmlEncode const& xmlEncode ) {
        xmlEncode.encodeTo( os );
        return os;
    }

    XmlWriter::ScopedElement::ScopedElement( XmlWriter* writer )
    :   m_writer( writer )
    {}

    XmlWriter::ScopedElement::ScopedElement( ScopedElement&& other ) DOCTEST_NOEXCEPT
    :   m_writer( other.m_writer ){
        other.m_writer = nullptr;
    }
    XmlWriter::ScopedElement& XmlWriter::ScopedElement::operator=( ScopedElement&& other ) DOCTEST_NOEXCEPT {
        if ( m_writer ) {
            m_writer->endElement();
        }
        m_writer = other.m_writer;
        other.m_writer = nullptr;
        return *this;
    }


    XmlWriter::ScopedElement::~ScopedElement() {
        if( m_writer )
            m_writer->endElement();
    }

    XmlWriter::ScopedElement& XmlWriter::ScopedElement::writeText( std::string const& text, bool indent ) {
        m_writer->writeText( text, indent );
        return *this;
    }

    XmlWriter::XmlWriter( std::ostream& os ) : m_os( os )
    {
        writeDeclaration();
    }

    XmlWriter::~XmlWriter() {
        while( !m_tags.empty() )
            endElement();
    }

    XmlWriter& XmlWriter::startElement( std::string const& name ) {
        ensureTagClosed();
        newlineIfNecessary();
        m_os << m_indent << '<' << name;
        m_tags.push_back( name );
        m_indent += "  ";
        m_tagIsOpen = true;
        return *this;
    }

    XmlWriter::ScopedElement XmlWriter::scopedElement( std::string const& name ) {
        ScopedElement scoped( this );
        startElement( name );
        return scoped;
    }

    XmlWriter& XmlWriter::endElement() {
        newlineIfNecessary();
        m_indent = m_indent.substr( 0, m_indent.size()-2 );
        if( m_tagIsOpen ) {
            m_os << "/>";
            m_tagIsOpen = false;
        }
        else {
            m_os << m_indent << "</" << m_tags.back() << ">";
        }
        m_os << std::endl;
        m_tags.pop_back();
        return *this;
    }

    XmlWriter& XmlWriter::writeAttribute( std::string const& name, std::string const& attribute ) {
        if( !name.empty() && !attribute.empty() )
            m_os << ' ' << name << "=\"" << XmlEncode( attribute, XmlEncode::ForAttributes ) << '"';
        return *this;
    }

    XmlWriter& XmlWriter::writeAttribute( std::string const& name, const char* attribute ) {
        if( !name.empty() && attribute && attribute[0] != '\0' )
            m_os << ' ' << name << "=\"" << XmlEncode( attribute, XmlEncode::ForAttributes ) << '"';
        return *this;
    }

    XmlWriter& XmlWriter::writeAttribute( std::string const& name, bool attribute ) {
        m_os << ' ' << name << "=\"" << ( attribute ? "true" : "false" ) << '"';
        return *this;
    }

    XmlWriter& XmlWriter::writeText( std::string const& text, bool indent ) {
        if( !text.empty() ){
            bool tagWasOpen = m_tagIsOpen;
            ensureTagClosed();
            if( tagWasOpen && indent )
                m_os << m_indent;
            m_os << XmlEncode( text );
            m_needsNewline = true;
        }
        return *this;
    }

    //XmlWriter& XmlWriter::writeComment( std::string const& text ) {
    //    ensureTagClosed();
    //    m_os << m_indent << "<!--" << text << "-->";
    //    m_needsNewline = true;
    //    return *this;
    //}

    //void XmlWriter::writeStylesheetRef( std::string const& url ) {
    //    m_os << "<?xml-stylesheet type=\"text/xsl\" href=\"" << url << "\"?>\n";
    //}

    //XmlWriter& XmlWriter::writeBlankLine() {
    //    ensureTagClosed();
    //    m_os << '\n';
    //    return *this;
    //}

    void XmlWriter::ensureTagClosed() {
        if( m_tagIsOpen ) {
            m_os << ">" << std::endl;
            m_tagIsOpen = false;
        }
    }

    void XmlWriter::writeDeclaration() {
        m_os << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    }

    void XmlWriter::newlineIfNecessary() {
        if( m_needsNewline ) {
            m_os << std::endl;
            m_needsNewline = false;
        }
    }

// =================================================================================================
// End of copy-pasted code from Catch
// =================================================================================================

    // clang-format on

    struct XmlReporter : public IReporter {
      XmlWriter xml;
      std::mutex mutex;

      // caching pointers/references to objects of these types - safe to do
      const ContextOptions &opt;
      const TestCaseData *tc = nullptr;

      XmlReporter(const ContextOptions &co)
          : xml(*co.cout), opt(co) {}

      void log_contexts() {
        int num_contexts = get_num_active_contexts();
        if (num_contexts) {
          auto contexts = get_active_contexts();
          std::stringstream ss;
          for (int i = 0; i < num_contexts; ++i) {
            contexts[i]->stringify(&ss);
            xml.scopedElement("Info").writeText(ss.str());
            ss.str("");
          }
        }
      }

      unsigned line(unsigned l) const { return opt.no_line_numbers ? 0 : l; }

      void test_case_start_impl(const TestCaseData &in) {
        bool open_ts_tag = false;
        if (tc != nullptr) {// we have already opened a test suite
          if (std::strcmp(tc->m_test_suite, in.m_test_suite) != 0) {
            xml.endElement();
            open_ts_tag = true;
          }
        } else {
          open_ts_tag = true;// first test case ==> first test suite
        }

        if (open_ts_tag) {
          xml.startElement("TestSuite");
          xml.writeAttribute("name", in.m_test_suite);
        }

        tc = &in;
        xml.startElement("TestCase")
                .writeAttribute("name", in.m_name)
                .writeAttribute("filename", skipPathFromFilename(in.m_file.c_str()))
                .writeAttribute("line", line(in.m_line))
                .writeAttribute("description", in.m_description);

        if (Approx(in.m_timeout) != 0)
          xml.writeAttribute("timeout", in.m_timeout);
        if (in.m_may_fail)
          xml.writeAttribute("may_fail", true);
        if (in.m_should_fail)
          xml.writeAttribute("should_fail", true);
      }

      // =========================================================================================
      // WHAT FOLLOWS ARE OVERRIDES OF THE VIRTUAL METHODS OF THE REPORTER INTERFACE
      // =========================================================================================

      void report_query(const QueryData &in) override {
        test_run_start();
        if (opt.list_reporters) {
          for (auto &curr: getListeners())
            xml.scopedElement("Listener")
                    .writeAttribute("priority", curr.first.first)
                    .writeAttribute("name", curr.first.second);
          for (auto &curr: getReporters())
            xml.scopedElement("Reporter")
                    .writeAttribute("priority", curr.first.first)
                    .writeAttribute("name", curr.first.second);
        } else if (opt.count || opt.list_test_cases) {
          for (unsigned i = 0; i < in.num_data; ++i) {
            xml.scopedElement("TestCase").writeAttribute("name", in.data[i]->m_name).writeAttribute("testsuite", in.data[i]->m_test_suite).writeAttribute("filename", skipPathFromFilename(in.data[i]->m_file.c_str())).writeAttribute("line", line(in.data[i]->m_line)).writeAttribute("skipped", in.data[i]->m_skip);
          }
          xml.scopedElement("OverallResultsTestCases")
                  .writeAttribute("unskipped", in.run_stats->numTestCasesPassingFilters);
        } else if (opt.list_test_suites) {
          for (unsigned i = 0; i < in.num_data; ++i)
            xml.scopedElement("TestSuite").writeAttribute("name", in.data[i]->m_test_suite);
          xml.scopedElement("OverallResultsTestCases")
                  .writeAttribute("unskipped", in.run_stats->numTestCasesPassingFilters);
          xml.scopedElement("OverallResultsTestSuites")
                  .writeAttribute("unskipped", in.run_stats->numTestSuitesPassingFilters);
        }
        xml.endElement();
      }

      void test_run_start() override {
        // remove .exe extension - mainly to have the same output on UNIX and Windows
        std::string binary_name = skipPathFromFilename(opt.binary_name.c_str());
#ifdef DOCTEST_PLATFORM_WINDOWS
        if (binary_name.rfind(".exe") != std::string::npos)
          binary_name = binary_name.substr(0, binary_name.length() - 4);
#endif// DOCTEST_PLATFORM_WINDOWS

        xml.startElement("doctest").writeAttribute("binary", binary_name);
        if (opt.no_version == false)
          xml.writeAttribute("version", DOCTEST_VERSION_STR);

        // only the consequential ones (TODO: filters)
        xml.scopedElement("Options")
                .writeAttribute("order_by", opt.order_by.c_str())
                .writeAttribute("rand_seed", opt.rand_seed)
                .writeAttribute("first", opt.first)
                .writeAttribute("last", opt.last)
                .writeAttribute("abort_after", opt.abort_after)
                .writeAttribute("subcase_filter_levels", opt.subcase_filter_levels)
                .writeAttribute("case_sensitive", opt.case_sensitive)
                .writeAttribute("no_throw", opt.no_throw)
                .writeAttribute("no_skip", opt.no_skip);
      }

      void test_run_end(const TestRunStats &p) override {
        if (tc)// the TestSuite tag - only if there has been at least 1 test case
          xml.endElement();

        xml.scopedElement("OverallResultsAsserts")
                .writeAttribute("successes", p.numAsserts - p.numAssertsFailed)
                .writeAttribute("failures", p.numAssertsFailed);

        xml.startElement("OverallResultsTestCases")
                .writeAttribute("successes",
                                p.numTestCasesPassingFilters - p.numTestCasesFailed)
                .writeAttribute("failures", p.numTestCasesFailed);
        if (opt.no_skipped_summary == false)
          xml.writeAttribute("skipped", p.numTestCases - p.numTestCasesPassingFilters);
        xml.endElement();

        xml.endElement();
      }

      void test_case_start(const TestCaseData &in) override {
        test_case_start_impl(in);
        xml.ensureTagClosed();
      }

      void test_case_reenter(const TestCaseData &) override {}

      void test_case_end(const CurrentTestCaseStats &st) override {
        xml.startElement("OverallResultsAsserts")
                .writeAttribute("successes",
                                st.numAssertsCurrentTest - st.numAssertsFailedCurrentTest)
                .writeAttribute("failures", st.numAssertsFailedCurrentTest)
                .writeAttribute("test_case_success", st.testCaseSuccess);
        if (opt.duration)
          xml.writeAttribute("duration", st.seconds);
        if (tc->m_expected_failures)
          xml.writeAttribute("expected_failures", tc->m_expected_failures);
        xml.endElement();

        xml.endElement();
      }

      void test_case_exception(const TestCaseException &e) override {
        std::lock_guard<std::mutex> lock(mutex);

        xml.scopedElement("Exception")
                .writeAttribute("crash", e.is_crash)
                .writeText(e.error_string.c_str());
      }

      void subcase_start(const SubcaseSignature &in) override {
        xml.startElement("SubCase")
                .writeAttribute("name", in.m_name)
                .writeAttribute("filename", skipPathFromFilename(in.m_file))
                .writeAttribute("line", line(in.m_line));
        xml.ensureTagClosed();
      }

      void subcase_end() override { xml.endElement(); }

      void log_assert(const AssertData &rb) override {
        if (!rb.m_failed && !opt.success)
          return;

        std::lock_guard<std::mutex> lock(mutex);

        xml.startElement("Expression")
                .writeAttribute("success", !rb.m_failed)
                .writeAttribute("type", assertString(rb.m_at))
                .writeAttribute("filename", skipPathFromFilename(rb.m_file))
                .writeAttribute("line", line(rb.m_line));

        xml.scopedElement("Original").writeText(rb.m_expr);

        if (rb.m_threw)
          xml.scopedElement("Exception").writeText(rb.m_exception.c_str());

        if (rb.m_at & assertType::is_throws_as)
          xml.scopedElement("ExpectedException").writeText(rb.m_exception_type);
        if (rb.m_at & assertType::is_throws_with)
          xml.scopedElement("ExpectedExceptionString").writeText(rb.m_exception_string);
        if ((rb.m_at & assertType::is_normal) && !rb.m_threw)
          xml.scopedElement("Expanded").writeText(rb.m_decomp.c_str());

        log_contexts();

        xml.endElement();
      }

      void log_message(const MessageData &mb) override {
        std::lock_guard<std::mutex> lock(mutex);

        xml.startElement("Message")
                .writeAttribute("type", failureString(mb.m_severity))
                .writeAttribute("filename", skipPathFromFilename(mb.m_file))
                .writeAttribute("line", line(mb.m_line));

        xml.scopedElement("Text").writeText(mb.m_string.c_str());

        log_contexts();

        xml.endElement();
      }

      void test_case_skipped(const TestCaseData &in) override {
        if (opt.no_skipped_summary == false) {
          test_case_start_impl(in);
          xml.writeAttribute("skipped", "true");
          xml.endElement();
        }
      }
    };

    DOCTEST_REGISTER_REPORTER("xml", 0, XmlReporter);

    void fulltext_log_assert_to_stream(std::ostream &s, const AssertData &rb) {
      if ((rb.m_at & (assertType::is_throws_as | assertType::is_throws_with)) ==
          0)//!OCLINT bitwise operator in conditional
        s << Color::Cyan << assertString(rb.m_at) << "( " << rb.m_expr << " ) "
          << Color::None;

      if (rb.m_at & assertType::is_throws) {//!OCLINT bitwise operator in conditional
        s << (rb.m_threw ? "threw as expected!" : "did NOT throw at all!") << "\n";
      } else if ((rb.m_at & assertType::is_throws_as) &&
                 (rb.m_at & assertType::is_throws_with)) {//!OCLINT
        s << Color::Cyan << assertString(rb.m_at) << "( " << rb.m_expr << ", \""
          << rb.m_exception_string << "\", " << rb.m_exception_type << " ) " << Color::None;
        if (rb.m_threw) {
          if (!rb.m_failed) {
            s << "threw as expected!\n";
          } else {
            s << "threw a DIFFERENT exception! (contents: " << rb.m_exception << ")\n";
          }
        } else {
          s << "did NOT throw at all!\n";
        }
      } else if (rb.m_at &
                 assertType::is_throws_as) {//!OCLINT bitwise operator in conditional
        s << Color::Cyan << assertString(rb.m_at) << "( " << rb.m_expr << ", "
          << rb.m_exception_type << " ) " << Color::None
          << (rb.m_threw ? (rb.m_threw_as ? "threw as expected!" : "threw a DIFFERENT exception: ") : "did NOT throw at all!")
          << Color::Cyan << rb.m_exception << "\n";
      } else if (rb.m_at &
                 assertType::is_throws_with) {//!OCLINT bitwise operator in conditional
        s << Color::Cyan << assertString(rb.m_at) << "( " << rb.m_expr << ", \""
          << rb.m_exception_string << "\" ) " << Color::None
          << (rb.m_threw ? (!rb.m_failed ? "threw as expected!" : "threw a DIFFERENT exception: ") : "did NOT throw at all!")
          << Color::Cyan << rb.m_exception << "\n";
      } else if (rb.m_at & assertType::is_nothrow) {//!OCLINT bitwise operator in conditional
        s << (rb.m_threw ? "THREW exception: " : "didn't throw!") << Color::Cyan
          << rb.m_exception << "\n";
      } else {
        s << (rb.m_threw ? "THREW exception: " : (!rb.m_failed ? "is correct!\n" : "is NOT correct!\n"));
        if (rb.m_threw)
          s << rb.m_exception << "\n";
        else
          s << "  values: " << assertString(rb.m_at) << "( " << rb.m_decomp << " )\n";
      }
    }

    // TODO:
    // - log_message()
    // - respond to queries
    // - honor remaining options
    // - more attributes in tags
    struct JUnitReporter : public IReporter {
      XmlWriter xml;
      std::mutex mutex;
      Timer timer;
      std::vector<String> deepestSubcaseStackNames;

      struct JUnitTestCaseData {
        static std::string getCurrentTimestamp() {
          // Beware, this is not reentrant because of backward compatibility issues
          // Also, UTC only, again because of backward compatibility (%z is C++11)
          time_t rawtime;
          std::time(&rawtime);
          auto const timeStampSize = sizeof("2017-01-16T17:06:45Z");

          std::tm timeInfo;
#ifdef DOCTEST_PLATFORM_WINDOWS
          gmtime_s(&timeInfo, &rawtime);
#else // DOCTEST_PLATFORM_WINDOWS
          gmtime_r(&rawtime, &timeInfo);
#endif// DOCTEST_PLATFORM_WINDOWS

          char timeStamp[timeStampSize];
          const char *const fmt = "%Y-%m-%dT%H:%M:%SZ";

          std::strftime(timeStamp, timeStampSize, fmt, &timeInfo);
          return std::string(timeStamp);
        }

        struct JUnitTestMessage {
          JUnitTestMessage(const std::string &_message, const std::string &_type, const std::string &_details)
              : message(_message), type(_type), details(_details) {}

          JUnitTestMessage(const std::string &_message, const std::string &_details)
              : message(_message), type(), details(_details) {}

          std::string message, type, details;
        };

        struct JUnitTestCase {
          JUnitTestCase(const std::string &_classname, const std::string &_name)
              : classname(_classname), name(_name), time(0), failures() {}

          std::string classname, name;
          double time;
          std::vector<JUnitTestMessage> failures, errors;
        };

        void add(const std::string &classname, const std::string &name) {
          testcases.emplace_back(classname, name);
        }

        void appendSubcaseNamesToLastTestcase(std::vector<String> nameStack) {
          for (auto &curr: nameStack)
            if (curr.size())
              testcases.back().name += std::string("/") + curr.c_str();
        }

        void addTime(double time) {
          if (time < 1e-4)
            time = 0;
          testcases.back().time = time;
          totalSeconds += time;
        }

        void addFailure(const std::string &message, const std::string &type, const std::string &details) {
          testcases.back().failures.emplace_back(message, type, details);
          ++totalFailures;
        }

        void addError(const std::string &message, const std::string &details) {
          testcases.back().errors.emplace_back(message, details);
          ++totalErrors;
        }

        std::vector<JUnitTestCase> testcases;
        double totalSeconds = 0;
        int totalErrors = 0, totalFailures = 0;
      };

      JUnitTestCaseData testCaseData;

      // caching pointers/references to objects of these types - safe to do
      const ContextOptions &opt;
      const TestCaseData *tc = nullptr;

      JUnitReporter(const ContextOptions &co)
          : xml(*co.cout), opt(co) {}

      unsigned line(unsigned l) const { return opt.no_line_numbers ? 0 : l; }

      // =========================================================================================
      // WHAT FOLLOWS ARE OVERRIDES OF THE VIRTUAL METHODS OF THE REPORTER INTERFACE
      // =========================================================================================

      void report_query(const QueryData &) override {}

      void test_run_start() override {}

      void test_run_end(const TestRunStats &p) override {
        // remove .exe extension - mainly to have the same output on UNIX and Windows
        std::string binary_name = skipPathFromFilename(opt.binary_name.c_str());
#ifdef DOCTEST_PLATFORM_WINDOWS
        if (binary_name.rfind(".exe") != std::string::npos)
          binary_name = binary_name.substr(0, binary_name.length() - 4);
#endif// DOCTEST_PLATFORM_WINDOWS
        xml.startElement("testsuites");
        xml.startElement("testsuite").writeAttribute("name", binary_name).writeAttribute("errors", testCaseData.totalErrors).writeAttribute("failures", testCaseData.totalFailures).writeAttribute("tests", p.numAsserts);
        if (opt.no_time_in_output == false) {
          xml.writeAttribute("time", testCaseData.totalSeconds);
          xml.writeAttribute("timestamp", JUnitTestCaseData::getCurrentTimestamp());
        }
        if (opt.no_version == false)
          xml.writeAttribute("doctest_version", DOCTEST_VERSION_STR);

        for (const auto &testCase: testCaseData.testcases) {
          xml.startElement("testcase")
                  .writeAttribute("classname", testCase.classname)
                  .writeAttribute("name", testCase.name);
          if (opt.no_time_in_output == false)
            xml.writeAttribute("time", testCase.time);
          // This is not ideal, but it should be enough to mimic gtest's junit output.
          xml.writeAttribute("status", "run");

          for (const auto &failure: testCase.failures) {
            xml.scopedElement("failure")
                    .writeAttribute("message", failure.message)
                    .writeAttribute("type", failure.type)
                    .writeText(failure.details, false);
          }

          for (const auto &error: testCase.errors) {
            xml.scopedElement("error")
                    .writeAttribute("message", error.message)
                    .writeText(error.details);
          }

          xml.endElement();
        }
        xml.endElement();
        xml.endElement();
      }

      void test_case_start(const TestCaseData &in) override {
        testCaseData.add(skipPathFromFilename(in.m_file.c_str()), in.m_name);
        timer.start();
      }

      void test_case_reenter(const TestCaseData &in) override {
        testCaseData.addTime(timer.getElapsedSeconds());
        testCaseData.appendSubcaseNamesToLastTestcase(deepestSubcaseStackNames);
        deepestSubcaseStackNames.clear();

        timer.start();
        testCaseData.add(skipPathFromFilename(in.m_file.c_str()), in.m_name);
      }

      void test_case_end(const CurrentTestCaseStats &) override {
        testCaseData.addTime(timer.getElapsedSeconds());
        testCaseData.appendSubcaseNamesToLastTestcase(deepestSubcaseStackNames);
        deepestSubcaseStackNames.clear();
      }

      void test_case_exception(const TestCaseException &e) override {
        std::lock_guard<std::mutex> lock(mutex);
        testCaseData.addError("exception", e.error_string.c_str());
      }

      void subcase_start(const SubcaseSignature &in) override {
        deepestSubcaseStackNames.push_back(in.m_name);
      }

      void subcase_end() override {}

      void log_assert(const AssertData &rb) override {
        if (!rb.m_failed)// report only failures & ignore the `success` option
          return;

        std::lock_guard<std::mutex> lock(mutex);

        std::ostringstream os;
        os << skipPathFromFilename(rb.m_file) << (opt.gnu_file_line ? ":" : "(")
           << line(rb.m_line) << (opt.gnu_file_line ? ":" : "):") << std::endl;

        fulltext_log_assert_to_stream(os, rb);
        log_contexts(os);
        testCaseData.addFailure(rb.m_decomp.c_str(), assertString(rb.m_at), os.str());
      }

      void log_message(const MessageData &) override {}

      void test_case_skipped(const TestCaseData &) override {}

      void log_contexts(std::ostringstream &s) {
        int num_contexts = get_num_active_contexts();
        if (num_contexts) {
          auto contexts = get_active_contexts();

          s << "  logged: ";
          for (int i = 0; i < num_contexts; ++i) {
            s << (i == 0 ? "" : "          ");
            contexts[i]->stringify(&s);
            s << std::endl;
          }
        }
      }
    };

    DOCTEST_REGISTER_REPORTER("junit", 0, JUnitReporter);

    struct Whitespace {
      int nrSpaces;
      explicit Whitespace(int nr)
          : nrSpaces(nr) {}
    };

    std::ostream &operator<<(std::ostream &out, const Whitespace &ws) {
      if (ws.nrSpaces != 0)
        out << std::setw(ws.nrSpaces) << ' ';
      return out;
    }

    struct ConsoleReporter : public IReporter {
      std::ostream &s;
      bool hasLoggedCurrentTestStart;
      std::vector<SubcaseSignature> subcasesStack;
      size_t currentSubcaseLevel;
      std::mutex mutex;

      // caching pointers/references to objects of these types - safe to do
      const ContextOptions &opt;
      const TestCaseData *tc;

      ConsoleReporter(const ContextOptions &co)
          : s(*co.cout), opt(co) {}

      ConsoleReporter(const ContextOptions &co, std::ostream &ostr)
          : s(ostr), opt(co) {}

      // =========================================================================================
      // WHAT FOLLOWS ARE HELPERS USED BY THE OVERRIDES OF THE VIRTUAL METHODS OF THE INTERFACE
      // =========================================================================================

      void separator_to_stream() {
        s << Color::Yellow
          << "==============================================================================="
             "\n";
      }

      const char *getSuccessOrFailString(bool success, assertType::Enum at,
                                         const char *success_str) {
        if (success)
          return success_str;
        return failureString(at);
      }

      Color::Enum getSuccessOrFailColor(bool success, assertType::Enum at) {
        return success ? Color::BrightGreen : (at & assertType::is_warn) ? Color::Yellow
                                                                         : Color::Red;
      }

      void successOrFailColoredStringToStream(bool success, assertType::Enum at,
                                              const char *success_str = "SUCCESS") {
        s << getSuccessOrFailColor(success, at)
          << getSuccessOrFailString(success, at, success_str) << ": ";
      }

      void log_contexts() {
        int num_contexts = get_num_active_contexts();
        if (num_contexts) {
          auto contexts = get_active_contexts();

          s << Color::None << "  logged: ";
          for (int i = 0; i < num_contexts; ++i) {
            s << (i == 0 ? "" : "          ");
            contexts[i]->stringify(&s);
            s << "\n";
          }
        }

        s << "\n";
      }

      // this was requested to be made virtual so users could override it
      virtual void file_line_to_stream(const char *file, int line,
                                       const char *tail = "") {
        s << Color::LightGrey << skipPathFromFilename(file) << (opt.gnu_file_line ? ":" : "(")
          << (opt.no_line_numbers ? 0 : line)// 0 or the real num depending on the option
          << (opt.gnu_file_line ? ":" : "):") << tail;
      }

      void logTestStart() {
        if (hasLoggedCurrentTestStart)
          return;

        separator_to_stream();
        file_line_to_stream(tc->m_file.c_str(), tc->m_line, "\n");
        if (tc->m_description)
          s << Color::Yellow << "DESCRIPTION: " << Color::None << tc->m_description << "\n";
        if (tc->m_test_suite && tc->m_test_suite[0] != '\0')
          s << Color::Yellow << "TEST SUITE: " << Color::None << tc->m_test_suite << "\n";
        if (strncmp(tc->m_name, "  Scenario:", 11) != 0)
          s << Color::Yellow << "TEST CASE:  ";
        s << Color::None << tc->m_name << "\n";

        for (size_t i = 0; i < currentSubcaseLevel; ++i) {
          if (subcasesStack[i].m_name[0] != '\0')
            s << "  " << subcasesStack[i].m_name << "\n";
        }

        if (currentSubcaseLevel != subcasesStack.size()) {
          s << Color::Yellow << "\nDEEPEST SUBCASE STACK REACHED (DIFFERENT FROM THE CURRENT ONE):\n"
            << Color::None;
          for (size_t i = 0; i < subcasesStack.size(); ++i) {
            if (subcasesStack[i].m_name[0] != '\0')
              s << "  " << subcasesStack[i].m_name << "\n";
          }
        }

        s << "\n";

        hasLoggedCurrentTestStart = true;
      }

      void printVersion() {
        if (opt.no_version == false)
          s << Color::Cyan << "[doctest] " << Color::None << "doctest version is \""
            << DOCTEST_VERSION_STR << "\"\n";
      }

      void printIntro() {
        if (opt.no_intro == false) {
          printVersion();
          s << Color::Cyan << "[doctest] " << Color::None
            << "run with \"--" DOCTEST_OPTIONS_PREFIX_DISPLAY "help\" for options\n";
        }
      }

      void printHelp() {
        int sizePrefixDisplay = static_cast<int>(strlen(DOCTEST_OPTIONS_PREFIX_DISPLAY));
        printVersion();
        // clang-format off
            s << Color::Cyan << "[doctest]\n" << Color::None;
            s << Color::Cyan << "[doctest] " << Color::None;
            s << "boolean values: \"1/on/yes/true\" or \"0/off/no/false\"\n";
            s << Color::Cyan << "[doctest] " << Color::None;
            s << "filter  values: \"str1,str2,str3\" (comma separated strings)\n";
            s << Color::Cyan << "[doctest]\n" << Color::None;
            s << Color::Cyan << "[doctest] " << Color::None;
            s << "filters use wildcards for matching strings\n";
            s << Color::Cyan << "[doctest] " << Color::None;
            s << "something passes a filter if any of the strings in a filter matches\n";
#ifndef DOCTEST_CONFIG_NO_UNPREFIXED_OPTIONS
            s << Color::Cyan << "[doctest]\n" << Color::None;
            s << Color::Cyan << "[doctest] " << Color::None;
            s << "ALL FLAGS, OPTIONS AND FILTERS ALSO AVAILABLE WITH A \"" DOCTEST_CONFIG_OPTIONS_PREFIX "\" PREFIX!!!\n";
#endif
            s << Color::Cyan << "[doctest]\n" << Color::None;
            s << Color::Cyan << "[doctest] " << Color::None;
            s << "Query flags - the program quits after them. Available:\n\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "?,   --" DOCTEST_OPTIONS_PREFIX_DISPLAY "help, -" DOCTEST_OPTIONS_PREFIX_DISPLAY "h                      "
              << Whitespace(sizePrefixDisplay*0) <<  "prints this message\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "v,   --" DOCTEST_OPTIONS_PREFIX_DISPLAY "version                       "
              << Whitespace(sizePrefixDisplay*1) << "prints the version\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "c,   --" DOCTEST_OPTIONS_PREFIX_DISPLAY "count                         "
              << Whitespace(sizePrefixDisplay*1) << "prints the number of matching tests\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "ltc, --" DOCTEST_OPTIONS_PREFIX_DISPLAY "list-test-cases               "
              << Whitespace(sizePrefixDisplay*1) << "lists all matching tests by name\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "lts, --" DOCTEST_OPTIONS_PREFIX_DISPLAY "list-test-suites              "
              << Whitespace(sizePrefixDisplay*1) << "lists all matching test suites\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "lr,  --" DOCTEST_OPTIONS_PREFIX_DISPLAY "list-reporters                "
              << Whitespace(sizePrefixDisplay*1) << "lists all registered reporters\n\n";
            // ================================================================================== << 79
            s << Color::Cyan << "[doctest] " << Color::None;
            s << "The available <int>/<string> options/filters are:\n\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "tc,  --" DOCTEST_OPTIONS_PREFIX_DISPLAY "test-case=<filters>           "
              << Whitespace(sizePrefixDisplay*1) << "filters     tests by their name\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "tce, --" DOCTEST_OPTIONS_PREFIX_DISPLAY "test-case-exclude=<filters>   "
              << Whitespace(sizePrefixDisplay*1) << "filters OUT tests by their name\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "sf,  --" DOCTEST_OPTIONS_PREFIX_DISPLAY "source-file=<filters>         "
              << Whitespace(sizePrefixDisplay*1) << "filters     tests by their file\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "sfe, --" DOCTEST_OPTIONS_PREFIX_DISPLAY "source-file-exclude=<filters> "
              << Whitespace(sizePrefixDisplay*1) << "filters OUT tests by their file\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "ts,  --" DOCTEST_OPTIONS_PREFIX_DISPLAY "test-suite=<filters>          "
              << Whitespace(sizePrefixDisplay*1) << "filters     tests by their test suite\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "tse, --" DOCTEST_OPTIONS_PREFIX_DISPLAY "test-suite-exclude=<filters>  "
              << Whitespace(sizePrefixDisplay*1) << "filters OUT tests by their test suite\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "sc,  --" DOCTEST_OPTIONS_PREFIX_DISPLAY "subcase=<filters>             "
              << Whitespace(sizePrefixDisplay*1) << "filters     subcases by their name\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "sce, --" DOCTEST_OPTIONS_PREFIX_DISPLAY "subcase-exclude=<filters>     "
              << Whitespace(sizePrefixDisplay*1) << "filters OUT subcases by their name\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "r,   --" DOCTEST_OPTIONS_PREFIX_DISPLAY "reporters=<filters>           "
              << Whitespace(sizePrefixDisplay*1) << "reporters to use (console is default)\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "o,   --" DOCTEST_OPTIONS_PREFIX_DISPLAY "out=<string>                  "
              << Whitespace(sizePrefixDisplay*1) << "output filename\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "ob,  --" DOCTEST_OPTIONS_PREFIX_DISPLAY "order-by=<string>             "
              << Whitespace(sizePrefixDisplay*1) << "how the tests should be ordered\n";
            s << Whitespace(sizePrefixDisplay*3) << "                                       <string> - [file/suite/name/rand/none]\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "rs,  --" DOCTEST_OPTIONS_PREFIX_DISPLAY "rand-seed=<int>               "
              << Whitespace(sizePrefixDisplay*1) << "seed for random ordering\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "f,   --" DOCTEST_OPTIONS_PREFIX_DISPLAY "first=<int>                   "
              << Whitespace(sizePrefixDisplay*1) << "the first test passing the filters to\n";
            s << Whitespace(sizePrefixDisplay*3) << "                                       execute - for range-based execution\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "l,   --" DOCTEST_OPTIONS_PREFIX_DISPLAY "last=<int>                    "
              << Whitespace(sizePrefixDisplay*1) << "the last test passing the filters to\n";
            s << Whitespace(sizePrefixDisplay*3) << "                                       execute - for range-based execution\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "aa,  --" DOCTEST_OPTIONS_PREFIX_DISPLAY "abort-after=<int>             "
              << Whitespace(sizePrefixDisplay*1) << "stop after <int> failed assertions\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "scfl,--" DOCTEST_OPTIONS_PREFIX_DISPLAY "subcase-filter-levels=<int>   "
              << Whitespace(sizePrefixDisplay*1) << "apply filters for the first <int> levels\n";
            s << Color::Cyan << "\n[doctest] " << Color::None;
            s << "Bool options - can be used like flags and true is assumed. Available:\n\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "s,   --" DOCTEST_OPTIONS_PREFIX_DISPLAY "success=<bool>                "
              << Whitespace(sizePrefixDisplay*1) << "include successful assertions in output\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "cs,  --" DOCTEST_OPTIONS_PREFIX_DISPLAY "case-sensitive=<bool>         "
              << Whitespace(sizePrefixDisplay*1) << "filters being treated as case sensitive\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "e,   --" DOCTEST_OPTIONS_PREFIX_DISPLAY "exit=<bool>                   "
              << Whitespace(sizePrefixDisplay*1) << "exits after the tests finish\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "d,   --" DOCTEST_OPTIONS_PREFIX_DISPLAY "duration=<bool>               "
              << Whitespace(sizePrefixDisplay*1) << "prints the time duration of each test\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "m,   --" DOCTEST_OPTIONS_PREFIX_DISPLAY "minimal=<bool>                "
              << Whitespace(sizePrefixDisplay*1) << "minimal console output (only failures)\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "q,   --" DOCTEST_OPTIONS_PREFIX_DISPLAY "quiet=<bool>                  "
              << Whitespace(sizePrefixDisplay*1) << "no console output\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "nt,  --" DOCTEST_OPTIONS_PREFIX_DISPLAY "no-throw=<bool>               "
              << Whitespace(sizePrefixDisplay*1) << "skips exceptions-related assert checks\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "ne,  --" DOCTEST_OPTIONS_PREFIX_DISPLAY "no-exitcode=<bool>            "
              << Whitespace(sizePrefixDisplay*1) << "returns (or exits) always with success\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "nr,  --" DOCTEST_OPTIONS_PREFIX_DISPLAY "no-run=<bool>                 "
              << Whitespace(sizePrefixDisplay*1) << "skips all runtime doctest operations\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "ni,  --" DOCTEST_OPTIONS_PREFIX_DISPLAY "no-intro=<bool>               "
              << Whitespace(sizePrefixDisplay*1) << "omit the framework intro in the output\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "nv,  --" DOCTEST_OPTIONS_PREFIX_DISPLAY "no-version=<bool>             "
              << Whitespace(sizePrefixDisplay*1) << "omit the framework version in the output\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "nc,  --" DOCTEST_OPTIONS_PREFIX_DISPLAY "no-colors=<bool>              "
              << Whitespace(sizePrefixDisplay*1) << "disables colors in output\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "fc,  --" DOCTEST_OPTIONS_PREFIX_DISPLAY "force-colors=<bool>           "
              << Whitespace(sizePrefixDisplay*1) << "use colors even when not in a tty\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "nb,  --" DOCTEST_OPTIONS_PREFIX_DISPLAY "no-breaks=<bool>              "
              << Whitespace(sizePrefixDisplay*1) << "disables breakpoints in debuggers\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "ns,  --" DOCTEST_OPTIONS_PREFIX_DISPLAY "no-skip=<bool>                "
              << Whitespace(sizePrefixDisplay*1) << "don't skip test cases marked as skip\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "gfl, --" DOCTEST_OPTIONS_PREFIX_DISPLAY "gnu-file-line=<bool>          "
              << Whitespace(sizePrefixDisplay*1) << ":n: vs (n): for line numbers in output\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "npf, --" DOCTEST_OPTIONS_PREFIX_DISPLAY "no-path-filenames=<bool>      "
              << Whitespace(sizePrefixDisplay*1) << "only filenames and no paths in output\n";
            s << " -" DOCTEST_OPTIONS_PREFIX_DISPLAY "nln, --" DOCTEST_OPTIONS_PREFIX_DISPLAY "no-line-numbers=<bool>        "
              << Whitespace(sizePrefixDisplay*1) << "0 instead of real line numbers in output\n";
            // ================================================================================== << 79
        // clang-format on

        s << Color::Cyan << "\n[doctest] " << Color::None;
        s << "for more information visit the project documentation\n\n";
      }

      void printRegisteredReporters() {
        printVersion();
        auto printReporters = [this](const reporterMap &reporters, const char *type) {
          if (reporters.size()) {
            s << Color::Cyan << "[doctest] " << Color::None << "listing all registered " << type << "\n";
            for (auto &curr: reporters)
              s << "priority: " << std::setw(5) << curr.first.first
                << " name: " << curr.first.second << "\n";
          }
        };
        printReporters(getListeners(), "listeners");
        printReporters(getReporters(), "reporters");
      }

      // =========================================================================================
      // WHAT FOLLOWS ARE OVERRIDES OF THE VIRTUAL METHODS OF THE REPORTER INTERFACE
      // =========================================================================================

      void report_query(const QueryData &in) override {
        if (opt.version) {
          printVersion();
        } else if (opt.help) {
          printHelp();
        } else if (opt.list_reporters) {
          printRegisteredReporters();
        } else if (opt.count || opt.list_test_cases) {
          if (opt.list_test_cases) {
            s << Color::Cyan << "[doctest] " << Color::None
              << "listing all test case names\n";
            separator_to_stream();
          }

          for (unsigned i = 0; i < in.num_data; ++i)
            s << Color::None << in.data[i]->m_name << "\n";

          separator_to_stream();

          s << Color::Cyan << "[doctest] " << Color::None
            << "unskipped test cases passing the current filters: "
            << g_cs->numTestCasesPassingFilters << "\n";

        } else if (opt.list_test_suites) {
          s << Color::Cyan << "[doctest] " << Color::None << "listing all test suites\n";
          separator_to_stream();

          for (unsigned i = 0; i < in.num_data; ++i)
            s << Color::None << in.data[i]->m_test_suite << "\n";

          separator_to_stream();

          s << Color::Cyan << "[doctest] " << Color::None
            << "unskipped test cases passing the current filters: "
            << g_cs->numTestCasesPassingFilters << "\n";
          s << Color::Cyan << "[doctest] " << Color::None
            << "test suites with unskipped test cases passing the current filters: "
            << g_cs->numTestSuitesPassingFilters << "\n";
        }
      }

      void test_run_start() override {
        if (!opt.minimal)
          printIntro();
      }

      void test_run_end(const TestRunStats &p) override {
        if (opt.minimal && p.numTestCasesFailed == 0)
          return;

        separator_to_stream();
        s << std::dec;

        auto totwidth = int(std::ceil(log10((std::max(p.numTestCasesPassingFilters, static_cast<unsigned>(p.numAsserts))) + 1)));
        auto passwidth = int(std::ceil(log10((std::max(p.numTestCasesPassingFilters - p.numTestCasesFailed, static_cast<unsigned>(p.numAsserts - p.numAssertsFailed))) + 1)));
        auto failwidth = int(std::ceil(log10((std::max(p.numTestCasesFailed, static_cast<unsigned>(p.numAssertsFailed))) + 1)));
        const bool anythingFailed = p.numTestCasesFailed > 0 || p.numAssertsFailed > 0;
        s << Color::Cyan << "[doctest] " << Color::None << "test cases: " << std::setw(totwidth)
          << p.numTestCasesPassingFilters << " | "
          << ((p.numTestCasesPassingFilters == 0 || anythingFailed) ? Color::None : Color::Green)
          << std::setw(passwidth) << p.numTestCasesPassingFilters - p.numTestCasesFailed << " passed"
          << Color::None << " | " << (p.numTestCasesFailed > 0 ? Color::Red : Color::None)
          << std::setw(failwidth) << p.numTestCasesFailed << " failed" << Color::None << " |";
        if (opt.no_skipped_summary == false) {
          const int numSkipped = p.numTestCases - p.numTestCasesPassingFilters;
          s << " " << (numSkipped == 0 ? Color::None : Color::Yellow) << numSkipped
            << " skipped" << Color::None;
        }
        s << "\n";
        s << Color::Cyan << "[doctest] " << Color::None << "assertions: " << std::setw(totwidth)
          << p.numAsserts << " | "
          << ((p.numAsserts == 0 || anythingFailed) ? Color::None : Color::Green)
          << std::setw(passwidth) << (p.numAsserts - p.numAssertsFailed) << " passed" << Color::None
          << " | " << (p.numAssertsFailed > 0 ? Color::Red : Color::None) << std::setw(failwidth)
          << p.numAssertsFailed << " failed" << Color::None << " |\n";
        s << Color::Cyan << "[doctest] " << Color::None
          << "Status: " << (p.numTestCasesFailed > 0 ? Color::Red : Color::Green)
          << ((p.numTestCasesFailed > 0) ? "FAILURE!" : "SUCCESS!") << Color::None << std::endl;
      }

      void test_case_start(const TestCaseData &in) override {
        hasLoggedCurrentTestStart = false;
        tc = &in;
        subcasesStack.clear();
        currentSubcaseLevel = 0;
      }

      void test_case_reenter(const TestCaseData &) override {
        subcasesStack.clear();
      }

      void test_case_end(const CurrentTestCaseStats &st) override {
        if (tc->m_no_output)
          return;

        // log the preamble of the test case only if there is something
        // else to print - something other than that an assert has failed
        if (opt.duration ||
            (st.failure_flags && st.failure_flags != TestCaseFailureReason::AssertFailure))
          logTestStart();

        if (opt.duration)
          s << Color::None << std::setprecision(6) << std::fixed << st.seconds
            << " s: " << tc->m_name << "\n";

        if (st.failure_flags & TestCaseFailureReason::Timeout)
          s << Color::Red << "Test case exceeded time limit of " << std::setprecision(6)
            << std::fixed << tc->m_timeout << "!\n";

        if (st.failure_flags & TestCaseFailureReason::ShouldHaveFailedButDidnt) {
          s << Color::Red << "Should have failed but didn't! Marking it as failed!\n";
        } else if (st.failure_flags & TestCaseFailureReason::ShouldHaveFailedAndDid) {
          s << Color::Yellow << "Failed as expected so marking it as not failed\n";
        } else if (st.failure_flags & TestCaseFailureReason::CouldHaveFailedAndDid) {
          s << Color::Yellow << "Allowed to fail so marking it as not failed\n";
        } else if (st.failure_flags & TestCaseFailureReason::DidntFailExactlyNumTimes) {
          s << Color::Red << "Didn't fail exactly " << tc->m_expected_failures
            << " times so marking it as failed!\n";
        } else if (st.failure_flags & TestCaseFailureReason::FailedExactlyNumTimes) {
          s << Color::Yellow << "Failed exactly " << tc->m_expected_failures
            << " times as expected so marking it as not failed!\n";
        }
        if (st.failure_flags & TestCaseFailureReason::TooManyFailedAsserts) {
          s << Color::Red << "Aborting - too many failed asserts!\n";
        }
        s << Color::None;// lgtm [cpp/useless-expression]
      }

      void test_case_exception(const TestCaseException &e) override {
        std::lock_guard<std::mutex> lock(mutex);
        if (tc->m_no_output)
          return;

        logTestStart();

        file_line_to_stream(tc->m_file.c_str(), tc->m_line, " ");
        successOrFailColoredStringToStream(false, e.is_crash ? assertType::is_require : assertType::is_check);
        s << Color::Red << (e.is_crash ? "test case CRASHED: " : "test case THREW exception: ")
          << Color::Cyan << e.error_string << "\n";

        int num_stringified_contexts = get_num_stringified_contexts();
        if (num_stringified_contexts) {
          auto stringified_contexts = get_stringified_contexts();
          s << Color::None << "  logged: ";
          for (int i = num_stringified_contexts; i > 0; --i) {
            s << (i == num_stringified_contexts ? "" : "          ")
              << stringified_contexts[i - 1] << "\n";
          }
        }
        s << "\n"
          << Color::None;
      }

      void subcase_start(const SubcaseSignature &subc) override {
        subcasesStack.push_back(subc);
        ++currentSubcaseLevel;
        hasLoggedCurrentTestStart = false;
      }

      void subcase_end() override {
        --currentSubcaseLevel;
        hasLoggedCurrentTestStart = false;
      }

      void log_assert(const AssertData &rb) override {
        if ((!rb.m_failed && !opt.success) || tc->m_no_output)
          return;

        std::lock_guard<std::mutex> lock(mutex);

        logTestStart();

        file_line_to_stream(rb.m_file, rb.m_line, " ");
        successOrFailColoredStringToStream(!rb.m_failed, rb.m_at);

        fulltext_log_assert_to_stream(s, rb);

        log_contexts();
      }

      void log_message(const MessageData &mb) override {
        if (tc->m_no_output)
          return;

        std::lock_guard<std::mutex> lock(mutex);

        logTestStart();

        file_line_to_stream(mb.m_file, mb.m_line, " ");
        s << getSuccessOrFailColor(false, mb.m_severity)
          << getSuccessOrFailString(mb.m_severity & assertType::is_warn, mb.m_severity,
                                    "MESSAGE")
          << ": ";
        s << Color::None << mb.m_string << "\n";
        log_contexts();
      }

      void test_case_skipped(const TestCaseData &) override {}
    };

    DOCTEST_REGISTER_REPORTER("console", 0, ConsoleReporter);

#ifdef DOCTEST_PLATFORM_WINDOWS
    struct DebugOutputWindowReporter : public ConsoleReporter {
      DOCTEST_THREAD_LOCAL static std::ostringstream oss;

      DebugOutputWindowReporter(const ContextOptions &co)
          : ConsoleReporter(co, oss) {}

#define DOCTEST_DEBUG_OUTPUT_REPORTER_OVERRIDE(func, type, arg) \
  void func(type arg) override {                                \
    bool with_col = g_no_colors;                                \
    g_no_colors = false;                                        \
    ConsoleReporter::func(arg);                                 \
    if (oss.tellp() != std::streampos{}) {                      \
      DOCTEST_OUTPUT_DEBUG_STRING(oss.str().c_str());           \
      oss.str("");                                              \
    }                                                           \
    g_no_colors = with_col;                                     \
  }

      DOCTEST_DEBUG_OUTPUT_REPORTER_OVERRIDE(test_run_start, DOCTEST_EMPTY, DOCTEST_EMPTY)
      DOCTEST_DEBUG_OUTPUT_REPORTER_OVERRIDE(test_run_end, const TestRunStats &, in)
      DOCTEST_DEBUG_OUTPUT_REPORTER_OVERRIDE(test_case_start, const TestCaseData &, in)
      DOCTEST_DEBUG_OUTPUT_REPORTER_OVERRIDE(test_case_reenter, const TestCaseData &, in)
      DOCTEST_DEBUG_OUTPUT_REPORTER_OVERRIDE(test_case_end, const CurrentTestCaseStats &, in)
      DOCTEST_DEBUG_OUTPUT_REPORTER_OVERRIDE(test_case_exception, const TestCaseException &, in)
      DOCTEST_DEBUG_OUTPUT_REPORTER_OVERRIDE(subcase_start, const SubcaseSignature &, in)
      DOCTEST_DEBUG_OUTPUT_REPORTER_OVERRIDE(subcase_end, DOCTEST_EMPTY, DOCTEST_EMPTY)
      DOCTEST_DEBUG_OUTPUT_REPORTER_OVERRIDE(log_assert, const AssertData &, in)
      DOCTEST_DEBUG_OUTPUT_REPORTER_OVERRIDE(log_message, const MessageData &, in)
      DOCTEST_DEBUG_OUTPUT_REPORTER_OVERRIDE(test_case_skipped, const TestCaseData &, in)
    };

    DOCTEST_THREAD_LOCAL std::ostringstream DebugOutputWindowReporter::oss;
#endif// DOCTEST_PLATFORM_WINDOWS

    // the implementation of parseOption()
    bool parseOptionImpl(int argc, const char *const *argv, const char *pattern, String *value) {
      // going from the end to the beginning and stopping on the first occurrence from the end
      for (int i = argc; i > 0; --i) {
        auto index = i - 1;
        auto temp = std::strstr(argv[index], pattern);
        if (temp && (value || strlen(temp) == strlen(pattern))) {//!OCLINT prefer early exits and continue
          // eliminate matches in which the chars before the option are not '-'
          bool noBadCharsFound = true;
          auto curr = argv[index];
          while (curr != temp) {
            if (*curr++ != '-') {
              noBadCharsFound = false;
              break;
            }
          }
          if (noBadCharsFound && argv[index][0] == '-') {
            if (value) {
              // parsing the value of an option
              temp += strlen(pattern);
              const unsigned len = strlen(temp);
              if (len) {
                *value = temp;
                return true;
              }
            } else {
              // just a flag - no value
              return true;
            }
          }
        }
      }
      return false;
    }

    // parses an option and returns the string after the '=' character
    bool parseOption(int argc, const char *const *argv, const char *pattern, String *value = nullptr,
                     const String &defaultVal = String()) {
      if (value)
        *value = defaultVal;
#ifndef DOCTEST_CONFIG_NO_UNPREFIXED_OPTIONS
      // offset (normally 3 for "dt-") to skip prefix
      if (parseOptionImpl(argc, argv, pattern + strlen(DOCTEST_CONFIG_OPTIONS_PREFIX), value))
        return true;
#endif// DOCTEST_CONFIG_NO_UNPREFIXED_OPTIONS
      return parseOptionImpl(argc, argv, pattern, value);
    }

    // locates a flag on the command line
    bool parseFlag(int argc, const char *const *argv, const char *pattern) {
      return parseOption(argc, argv, pattern);
    }

    // parses a comma separated list of words after a pattern in one of the arguments in argv
    bool parseCommaSepArgs(int argc, const char *const *argv, const char *pattern,
                           std::vector<String> &res) {
      String filtersString;
      if (parseOption(argc, argv, pattern, &filtersString)) {
        // tokenize with "," as a separator, unless escaped with backslash
        std::ostringstream s;
        auto flush = [&s, &res]() {
          auto string = s.str();
          if (string.size() > 0) {
            res.push_back(string.c_str());
          }
          s.str("");
        };

        bool seenBackslash = false;
        const char *current = filtersString.c_str();
        const char *end = current + strlen(current);
        while (current != end) {
          char character = *current++;
          if (seenBackslash) {
            seenBackslash = false;
            if (character == ',') {
              s.put(',');
              continue;
            }
            s.put('\\');
          }
          if (character == '\\') {
            seenBackslash = true;
          } else if (character == ',') {
            flush();
          } else {
            s.put(character);
          }
        }

        if (seenBackslash) {
          s.put('\\');
        }
        flush();
        return true;
      }
      return false;
    }

    enum optionType {
      option_bool,
      option_int
    };

    // parses an int/bool option from the command line
    bool parseIntOption(int argc, const char *const *argv, const char *pattern, optionType type,
                        int &res) {
      String parsedValue;
      if (!parseOption(argc, argv, pattern, &parsedValue))
        return false;

      if (type == 0) {
        // boolean
        const char positive[][5] = {"1", "true", "on", "yes"}; // 5 - strlen("true") + 1
        const char negative[][6] = {"0", "false", "off", "no"};// 6 - strlen("false") + 1

        // if the value matches any of the positive/negative possibilities
        for (unsigned i = 0; i < 4; i++) {
          if (parsedValue.compare(positive[i], true) == 0) {
            res = 1;//!OCLINT parameter reassignment
            return true;
          }
          if (parsedValue.compare(negative[i], true) == 0) {
            res = 0;//!OCLINT parameter reassignment
            return true;
          }
        }
      } else {
        // integer
        // TODO: change this to use std::stoi or something else! currently it uses undefined behavior - assumes '0' on failed parse...
        int theInt = std::atoi(parsedValue.c_str());// NOLINT
        if (theInt != 0) {
          res = theInt;//!OCLINT parameter reassignment
          return true;
        }
      }
      return false;
    }
  }// namespace

  Context::Context(int argc, const char *const *argv)
      : p(new detail::ContextState) {
    parseArgs(argc, argv, true);
    if (argc)
      p->binary_name = argv[0];
  }

  Context::~Context() {
    if (g_cs == p)
      g_cs = nullptr;
    delete p;
  }

  void Context::applyCommandLine(int argc, const char *const *argv) {
    parseArgs(argc, argv);
    if (argc)
      p->binary_name = argv[0];
  }

  // parses args
  void Context::parseArgs(int argc, const char *const *argv, bool withDefaults) {
    using namespace detail;

    // clang-format off
    parseCommaSepArgs(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "source-file=",        p->filters[0]);
    parseCommaSepArgs(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "sf=",                 p->filters[0]);
    parseCommaSepArgs(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "source-file-exclude=",p->filters[1]);
    parseCommaSepArgs(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "sfe=",                p->filters[1]);
    parseCommaSepArgs(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "test-suite=",         p->filters[2]);
    parseCommaSepArgs(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "ts=",                 p->filters[2]);
    parseCommaSepArgs(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "test-suite-exclude=", p->filters[3]);
    parseCommaSepArgs(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "tse=",                p->filters[3]);
    parseCommaSepArgs(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "test-case=",          p->filters[4]);
    parseCommaSepArgs(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "tc=",                 p->filters[4]);
    parseCommaSepArgs(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "test-case-exclude=",  p->filters[5]);
    parseCommaSepArgs(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "tce=",                p->filters[5]);
    parseCommaSepArgs(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "subcase=",            p->filters[6]);
    parseCommaSepArgs(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "sc=",                 p->filters[6]);
    parseCommaSepArgs(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "subcase-exclude=",    p->filters[7]);
    parseCommaSepArgs(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "sce=",                p->filters[7]);
    parseCommaSepArgs(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "reporters=",          p->filters[8]);
    parseCommaSepArgs(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "r=",                  p->filters[8]);
    // clang-format on

    int intRes = 0;
    String strRes;

#define DOCTEST_PARSE_AS_BOOL_OR_FLAG(name, sname, var, default)                                 \
  if (parseIntOption(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX name "=", option_bool, intRes) || \
      parseIntOption(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX sname "=", option_bool, intRes))  \
    p->var = static_cast<bool>(intRes);                                                          \
  else if (parseFlag(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX name) ||                          \
           parseFlag(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX sname))                           \
    p->var = true;                                                                               \
  else if (withDefaults)                                                                         \
  p->var = default

#define DOCTEST_PARSE_INT_OPTION(name, sname, var, default)                                     \
  if (parseIntOption(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX name "=", option_int, intRes) || \
      parseIntOption(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX sname "=", option_int, intRes))  \
    p->var = intRes;                                                                            \
  else if (withDefaults)                                                                        \
  p->var = default

#define DOCTEST_PARSE_STR_OPTION(name, sname, var, default)                                 \
  if (parseOption(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX name "=", &strRes, default) ||  \
      parseOption(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX sname "=", &strRes, default) || \
      withDefaults)                                                                         \
  p->var = strRes

    // clang-format off
    DOCTEST_PARSE_STR_OPTION("out", "o", out, "");
    DOCTEST_PARSE_STR_OPTION("order-by", "ob", order_by, "file");
    DOCTEST_PARSE_INT_OPTION("rand-seed", "rs", rand_seed, 0);

    DOCTEST_PARSE_INT_OPTION("first", "f", first, 0);
    DOCTEST_PARSE_INT_OPTION("last", "l", last, UINT_MAX);

    DOCTEST_PARSE_INT_OPTION("abort-after", "aa", abort_after, 0);
    DOCTEST_PARSE_INT_OPTION("subcase-filter-levels", "scfl", subcase_filter_levels, INT_MAX);

    DOCTEST_PARSE_AS_BOOL_OR_FLAG("success", "s", success, false);
    DOCTEST_PARSE_AS_BOOL_OR_FLAG("case-sensitive", "cs", case_sensitive, false);
    DOCTEST_PARSE_AS_BOOL_OR_FLAG("exit", "e", exit, false);
    DOCTEST_PARSE_AS_BOOL_OR_FLAG("duration", "d", duration, false);
    DOCTEST_PARSE_AS_BOOL_OR_FLAG("minimal", "m", minimal, false);
    DOCTEST_PARSE_AS_BOOL_OR_FLAG("quiet", "q", quiet, false);
    DOCTEST_PARSE_AS_BOOL_OR_FLAG("no-throw", "nt", no_throw, false);
    DOCTEST_PARSE_AS_BOOL_OR_FLAG("no-exitcode", "ne", no_exitcode, false);
    DOCTEST_PARSE_AS_BOOL_OR_FLAG("no-run", "nr", no_run, false);
    DOCTEST_PARSE_AS_BOOL_OR_FLAG("no-intro", "ni", no_intro, false);
    DOCTEST_PARSE_AS_BOOL_OR_FLAG("no-version", "nv", no_version, false);
    DOCTEST_PARSE_AS_BOOL_OR_FLAG("no-colors", "nc", no_colors, false);
    DOCTEST_PARSE_AS_BOOL_OR_FLAG("force-colors", "fc", force_colors, false);
    DOCTEST_PARSE_AS_BOOL_OR_FLAG("no-breaks", "nb", no_breaks, false);
    DOCTEST_PARSE_AS_BOOL_OR_FLAG("no-skip", "ns", no_skip, false);
    DOCTEST_PARSE_AS_BOOL_OR_FLAG("gnu-file-line", "gfl", gnu_file_line, !bool(DOCTEST_MSVC));
    DOCTEST_PARSE_AS_BOOL_OR_FLAG("no-path-filenames", "npf", no_path_in_filenames, false);
    DOCTEST_PARSE_AS_BOOL_OR_FLAG("no-line-numbers", "nln", no_line_numbers, false);
    DOCTEST_PARSE_AS_BOOL_OR_FLAG("no-debug-output", "ndo", no_debug_output, false);
    DOCTEST_PARSE_AS_BOOL_OR_FLAG("no-skipped-summary", "nss", no_skipped_summary, false);
    DOCTEST_PARSE_AS_BOOL_OR_FLAG("no-time-in-output", "ntio", no_time_in_output, false);
    // clang-format on

    if (withDefaults) {
      p->help = false;
      p->version = false;
      p->count = false;
      p->list_test_cases = false;
      p->list_test_suites = false;
      p->list_reporters = false;
    }
    if (parseFlag(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "help") ||
        parseFlag(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "h") ||
        parseFlag(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "?")) {
      p->help = true;
      p->exit = true;
    }
    if (parseFlag(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "version") ||
        parseFlag(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "v")) {
      p->version = true;
      p->exit = true;
    }
    if (parseFlag(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "count") ||
        parseFlag(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "c")) {
      p->count = true;
      p->exit = true;
    }
    if (parseFlag(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "list-test-cases") ||
        parseFlag(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "ltc")) {
      p->list_test_cases = true;
      p->exit = true;
    }
    if (parseFlag(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "list-test-suites") ||
        parseFlag(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "lts")) {
      p->list_test_suites = true;
      p->exit = true;
    }
    if (parseFlag(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "list-reporters") ||
        parseFlag(argc, argv, DOCTEST_CONFIG_OPTIONS_PREFIX "lr")) {
      p->list_reporters = true;
      p->exit = true;
    }
  }

  // allows the user to add procedurally to the filters from the command line
  void Context::addFilter(const char *filter, const char *value) { setOption(filter, value); }

  // allows the user to clear all filters from the command line
  void Context::clearFilters() {
    for (auto &curr: p->filters)
      curr.clear();
  }

  // allows the user to override procedurally the bool options from the command line
  void Context::setOption(const char *option, bool value) {
    setOption(option, value ? "true" : "false");
  }

  // allows the user to override procedurally the int options from the command line
  void Context::setOption(const char *option, int value) {
    setOption(option, toString(value).c_str());
    // NOLINTNEXTLINE(clang-analyzer-cplusplus.NewDeleteLeaks)
  }

  // allows the user to override procedurally the string options from the command line
  void Context::setOption(const char *option, const char *value) {
    auto argv = String("-") + option + "=" + value;
    auto lvalue = argv.c_str();
    parseArgs(1, &lvalue);
  }

  // users should query this in their main() and exit the program if true
  bool Context::shouldExit() { return p->exit; }

  void Context::setAsDefaultForAssertsOutOfTestCases() { g_cs = p; }

  void Context::setAssertHandler(detail::assert_handler ah) { p->ah = ah; }

  void Context::setCout(std::ostream *out) { p->cout = out; }

  static class DiscardOStream : public std::ostream {
private:
    class : public std::streambuf {
  private:
      // allowing some buffering decreases the amount of calls to overflow
      char buf[1024];

  protected:
      std::streamsize xsputn(const char_type *, std::streamsize count) override { return count; }

      int_type overflow(int_type ch) override {
        setp(std::begin(buf), std::end(buf));
        return traits_type::not_eof(ch);
      }
    } discardBuf;

public:
    DiscardOStream()
        : std::ostream(&discardBuf) {}
  } discardOut;

  // the main function that does all the filtering and test running
  int Context::run() {
    using namespace detail;

    // save the old context state in case such was setup - for using asserts out of a testing context
    auto old_cs = g_cs;
    // this is the current contest
    g_cs = p;
    is_running_in_test = true;

    g_no_colors = p->no_colors;
    p->resetRunData();

    std::fstream fstr;
    if (p->cout == nullptr) {
      if (p->quiet) {
        p->cout = &discardOut;
      } else if (p->out.size()) {
        // to a file if specified
        fstr.open(p->out.c_str(), std::fstream::out);
        p->cout = &fstr;
      } else {
        // stdout by default
        p->cout = &std::cout;
      }
    }

    FatalConditionHandler::allocateAltStackMem();

    auto cleanup_and_return = [&]() {
      FatalConditionHandler::freeAltStackMem();

      if (fstr.is_open())
        fstr.close();

      // restore context
      g_cs = old_cs;
      is_running_in_test = false;

      // we have to free the reporters which were allocated when the run started
      for (auto &curr: p->reporters_currently_used)
        delete curr;
      p->reporters_currently_used.clear();

      if (p->numTestCasesFailed && !p->no_exitcode)
        return EXIT_FAILURE;
      return EXIT_SUCCESS;
    };

    // setup default reporter if none is given through the command line
    if (p->filters[8].empty())
      p->filters[8].push_back("console");

    // check to see if any of the registered reporters has been selected
    for (auto &curr: getReporters()) {
      if (matchesAny(curr.first.second.c_str(), p->filters[8], false, p->case_sensitive))
        p->reporters_currently_used.push_back(curr.second(*g_cs));
    }

    // TODO: check if there is nothing in reporters_currently_used

    // prepend all listeners
    for (auto &curr: getListeners())
      p->reporters_currently_used.insert(p->reporters_currently_used.begin(), curr.second(*g_cs));

#ifdef DOCTEST_PLATFORM_WINDOWS
    if (isDebuggerActive() && p->no_debug_output == false)
      p->reporters_currently_used.push_back(new DebugOutputWindowReporter(*g_cs));
#endif// DOCTEST_PLATFORM_WINDOWS

    // handle version, help and no_run
    if (p->no_run || p->version || p->help || p->list_reporters) {
      DOCTEST_ITERATE_THROUGH_REPORTERS(report_query, QueryData());

      return cleanup_and_return();
    }

    std::vector<const TestCase *> testArray;
    for (auto &curr: getRegisteredTests())
      testArray.push_back(&curr);
    p->numTestCases = testArray.size();

    // sort the collected records
    if (!testArray.empty()) {
      if (p->order_by.compare("file", true) == 0) {
        std::sort(testArray.begin(), testArray.end(), fileOrderComparator);
      } else if (p->order_by.compare("suite", true) == 0) {
        std::sort(testArray.begin(), testArray.end(), suiteOrderComparator);
      } else if (p->order_by.compare("name", true) == 0) {
        std::sort(testArray.begin(), testArray.end(), nameOrderComparator);
      } else if (p->order_by.compare("rand", true) == 0) {
        std::srand(p->rand_seed);

        // random_shuffle implementation
        const auto first = &testArray[0];
        for (size_t i = testArray.size() - 1; i > 0; --i) {
          int idxToSwap = std::rand() % (i + 1);// NOLINT

          const auto temp = first[i];

          first[i] = first[idxToSwap];
          first[idxToSwap] = temp;
        }
      } else if (p->order_by.compare("none", true) == 0) {
        // means no sorting - beneficial for death tests which call into the executable
        // with a specific test case in mind - we don't want to slow down the startup times
      }
    }

    std::set<String> testSuitesPassingFilt;

    bool query_mode = p->count || p->list_test_cases || p->list_test_suites;
    std::vector<const TestCaseData *> queryResults;

    if (!query_mode)
      DOCTEST_ITERATE_THROUGH_REPORTERS(test_run_start, DOCTEST_EMPTY);

    // invoke the registered functions if they match the filter criteria (or just count them)
    for (auto &curr: testArray) {
      const auto &tc = *curr;

      bool skip_me = false;
      if (tc.m_skip && !p->no_skip)
        skip_me = true;

      if (!matchesAny(tc.m_file.c_str(), p->filters[0], true, p->case_sensitive))
        skip_me = true;
      if (matchesAny(tc.m_file.c_str(), p->filters[1], false, p->case_sensitive))
        skip_me = true;
      if (!matchesAny(tc.m_test_suite, p->filters[2], true, p->case_sensitive))
        skip_me = true;
      if (matchesAny(tc.m_test_suite, p->filters[3], false, p->case_sensitive))
        skip_me = true;
      if (!matchesAny(tc.m_name, p->filters[4], true, p->case_sensitive))
        skip_me = true;
      if (matchesAny(tc.m_name, p->filters[5], false, p->case_sensitive))
        skip_me = true;

      if (!skip_me)
        p->numTestCasesPassingFilters++;

      // skip the test if it is not in the execution range
      if ((p->last < p->numTestCasesPassingFilters && p->first <= p->last) ||
          (p->first > p->numTestCasesPassingFilters))
        skip_me = true;

      if (skip_me) {
        if (!query_mode)
          DOCTEST_ITERATE_THROUGH_REPORTERS(test_case_skipped, tc);
        continue;
      }

      // do not execute the test if we are to only count the number of filter passing tests
      if (p->count)
        continue;

      // print the name of the test and don't execute it
      if (p->list_test_cases) {
        queryResults.push_back(&tc);
        continue;
      }

      // print the name of the test suite if not done already and don't execute it
      if (p->list_test_suites) {
        if ((testSuitesPassingFilt.count(tc.m_test_suite) == 0) && tc.m_test_suite[0] != '\0') {
          queryResults.push_back(&tc);
          testSuitesPassingFilt.insert(tc.m_test_suite);
          p->numTestSuitesPassingFilters++;
        }
        continue;
      }

      // execute the test if it passes all the filtering
      {
        p->currentTest = &tc;

        p->failure_flags = TestCaseFailureReason::None;
        p->seconds = 0;

        // reset atomic counters
        p->numAssertsFailedCurrentTest_atomic = 0;
        p->numAssertsCurrentTest_atomic = 0;

        p->subcasesPassed.clear();

        DOCTEST_ITERATE_THROUGH_REPORTERS(test_case_start, tc);

        p->timer.start();

        bool run_test = true;

        do {
          // reset some of the fields for subcases (except for the set of fully passed ones)
          p->should_reenter = false;
          p->subcasesCurrentMaxLevel = 0;
          p->subcasesStack.clear();

          p->shouldLogCurrentException = true;

          // reset stuff for logging with INFO()
          p->stringifiedContexts.clear();

#ifndef DOCTEST_CONFIG_NO_EXCEPTIONS
          try {
#endif// DOCTEST_CONFIG_NO_EXCEPTIONS \
        // MSVC 2015 diagnoses fatalConditionHandler as unused (because reset() is a static method)
            DOCTEST_MSVC_SUPPRESS_WARNING_WITH_PUSH(4101)// unreferenced local variable
            FatalConditionHandler fatalConditionHandler; // Handle signals
            // execute the test
            tc.m_test();
            fatalConditionHandler.reset();
            DOCTEST_MSVC_SUPPRESS_WARNING_POP
#ifndef DOCTEST_CONFIG_NO_EXCEPTIONS
          } catch (const TestFailureException &) {
            p->failure_flags |= TestCaseFailureReason::AssertFailure;
          } catch (...) {
            DOCTEST_ITERATE_THROUGH_REPORTERS(test_case_exception,
                                              {translateActiveException(), false});
            p->failure_flags |= TestCaseFailureReason::Exception;
          }
#endif// DOCTEST_CONFIG_NO_EXCEPTIONS

          // exit this loop if enough assertions have failed - even if there are more subcases
          if (p->abort_after > 0 &&
              p->numAssertsFailed + p->numAssertsFailedCurrentTest_atomic >= p->abort_after) {
            run_test = false;
            p->failure_flags |= TestCaseFailureReason::TooManyFailedAsserts;
          }

          if (p->should_reenter && run_test)
            DOCTEST_ITERATE_THROUGH_REPORTERS(test_case_reenter, tc);
          if (!p->should_reenter)
            run_test = false;
        } while (run_test);

        p->finalizeTestCaseData();

        DOCTEST_ITERATE_THROUGH_REPORTERS(test_case_end, *g_cs);

        p->currentTest = nullptr;

        // stop executing tests if enough assertions have failed
        if (p->abort_after > 0 && p->numAssertsFailed >= p->abort_after)
          break;
      }
    }

    if (!query_mode) {
      DOCTEST_ITERATE_THROUGH_REPORTERS(test_run_end, *g_cs);
    } else {
      QueryData qdata;
      qdata.run_stats = g_cs;
      qdata.data = queryResults.data();
      qdata.num_data = unsigned(queryResults.size());
      DOCTEST_ITERATE_THROUGH_REPORTERS(report_query, qdata);
    }

    return cleanup_and_return();
  }

  IReporter::~IReporter() = default;

  int IReporter::get_num_active_contexts() { return detail::g_infoContexts.size(); }
  const IContextScope *const *IReporter::get_active_contexts() {
    return get_num_active_contexts() ? &detail::g_infoContexts[0] : nullptr;
  }

  int IReporter::get_num_stringified_contexts() { return detail::g_cs->stringifiedContexts.size(); }
  const String *IReporter::get_stringified_contexts() {
    return get_num_stringified_contexts() ? &detail::g_cs->stringifiedContexts[0] : nullptr;
  }

  namespace detail {
    void registerReporterImpl(const char *name, int priority, reporterCreatorFunc c, bool isReporter) {
      if (isReporter)
        getReporters().insert(reporterMap::value_type(reporterMap::key_type(priority, name), c));
      else
        getListeners().insert(reporterMap::value_type(reporterMap::key_type(priority, name), c));
    }
  }// namespace detail

}// namespace doctest

#endif// DOCTEST_CONFIG_DISABLE

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#ifdef DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
DOCTEST_MSVC_SUPPRESS_WARNING_WITH_PUSH(4007)// 'function' : must be 'attribute' - see issue #182
int main(int argc, char **argv) { return doctest::Context(argc, argv).run(); }
DOCTEST_MSVC_SUPPRESS_WARNING_POP
#endif// DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

DOCTEST_CLANG_SUPPRESS_WARNING_POP
DOCTEST_MSVC_SUPPRESS_WARNING_POP
DOCTEST_GCC_SUPPRESS_WARNING_POP

DOCTEST_SUPPRESS_COMMON_WARNINGS_POP

#endif// DOCTEST_LIBRARY_IMPLEMENTATION
#endif// DOCTEST_CONFIG_IMPLEMENT

#endif//  SAMOS_DOCTEST