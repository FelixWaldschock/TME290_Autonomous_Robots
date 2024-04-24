
/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_SIM_KINEMATICSTATE_HPP
#define OPENDLV_SIM_KINEMATICSTATE_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace sim {
using namespace std::string_literals; // NOLINT
class LIB_API KinematicState {
    private:
        static constexpr const char* TheShortName = "KinematicState";
        static constexpr const char* TheLongName = "opendlv.sim.KinematicState";

    public:
        inline static int32_t ID() {
            return 1002;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        KinematicState() = default;
        KinematicState(const KinematicState&) = default;
        KinematicState& operator=(const KinematicState&) = default;
        KinematicState(KinematicState&&) = default;
        KinematicState& operator=(KinematicState&&) = default;
        ~KinematicState() = default;

    public:
        inline KinematicState& vx(const float &v) noexcept {
            m_vx = v;
            return *this;
        }
        inline float vx() const noexcept {
            return m_vx;
        }
        inline KinematicState& vy(const float &v) noexcept {
            m_vy = v;
            return *this;
        }
        inline float vy() const noexcept {
            return m_vy;
        }
        inline KinematicState& vz(const float &v) noexcept {
            m_vz = v;
            return *this;
        }
        inline float vz() const noexcept {
            return m_vz;
        }
        inline KinematicState& rollRate(const float &v) noexcept {
            m_rollRate = v;
            return *this;
        }
        inline float rollRate() const noexcept {
            return m_rollRate;
        }
        inline KinematicState& pitchRate(const float &v) noexcept {
            m_pitchRate = v;
            return *this;
        }
        inline float pitchRate() const noexcept {
            return m_pitchRate;
        }
        inline KinematicState& yawRate(const float &v) noexcept {
            m_yawRate = v;
            return *this;
        }
        inline float yawRate() const noexcept {
            return m_yawRate;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("vx"s), m_vx, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("vy"s), m_vy, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("vz"s), m_vz, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("float"s), std::move("rollRate"s), m_rollRate, visitor);
                return;
            }
            if (5 == fieldId) {
                doVisit(5, std::move("float"s), std::move("pitchRate"s), m_pitchRate, visitor);
                return;
            }
            if (6 == fieldId) {
                doVisit(6, std::move("float"s), std::move("yawRate"s), m_yawRate, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("vx"s), m_vx, visitor);
            doVisit(2, std::move("float"s), std::move("vy"s), m_vy, visitor);
            doVisit(3, std::move("float"s), std::move("vz"s), m_vz, visitor);
            doVisit(4, std::move("float"s), std::move("rollRate"s), m_rollRate, visitor);
            doVisit(5, std::move("float"s), std::move("pitchRate"s), m_pitchRate, visitor);
            doVisit(6, std::move("float"s), std::move("yawRate"s), m_yawRate, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("vx"s), m_vx, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("vy"s), m_vy, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("vz"s), m_vz, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("float"s), std::move("rollRate"s), m_rollRate, preVisit, visit, postVisit);
            doTripletForwardVisit(5, std::move("float"s), std::move("pitchRate"s), m_pitchRate, preVisit, visit, postVisit);
            doTripletForwardVisit(6, std::move("float"s), std::move("yawRate"s), m_yawRate, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_vx{ 0.0f }; // field identifier = 1.
        float m_vy{ 0.0f }; // field identifier = 2.
        float m_vz{ 0.0f }; // field identifier = 3.
        float m_rollRate{ 0.0f }; // field identifier = 4.
        float m_pitchRate{ 0.0f }; // field identifier = 5.
        float m_yawRate{ 0.0f }; // field identifier = 6.
};
}}

template<>
struct isVisitable<opendlv::sim::KinematicState> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::sim::KinematicState> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_SIM_FRAME_HPP
#define OPENDLV_SIM_FRAME_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace sim {
using namespace std::string_literals; // NOLINT
class LIB_API Frame {
    private:
        static constexpr const char* TheShortName = "Frame";
        static constexpr const char* TheLongName = "opendlv.sim.Frame";

    public:
        inline static int32_t ID() {
            return 1003;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        Frame() = default;
        Frame(const Frame&) = default;
        Frame& operator=(const Frame&) = default;
        Frame(Frame&&) = default;
        Frame& operator=(Frame&&) = default;
        ~Frame() = default;

    public:
        inline Frame& x(const float &v) noexcept {
            m_x = v;
            return *this;
        }
        inline float x() const noexcept {
            return m_x;
        }
        inline Frame& y(const float &v) noexcept {
            m_y = v;
            return *this;
        }
        inline float y() const noexcept {
            return m_y;
        }
        inline Frame& z(const float &v) noexcept {
            m_z = v;
            return *this;
        }
        inline float z() const noexcept {
            return m_z;
        }
        inline Frame& qx(const float &v) noexcept {
            m_qx = v;
            return *this;
        }
        inline float qx() const noexcept {
            return m_qx;
        }
        inline Frame& qy(const float &v) noexcept {
            m_qy = v;
            return *this;
        }
        inline float qy() const noexcept {
            return m_qy;
        }
        inline Frame& qz(const float &v) noexcept {
            m_qz = v;
            return *this;
        }
        inline float qz() const noexcept {
            return m_qz;
        }
        inline Frame& qw(const float &v) noexcept {
            m_qw = v;
            return *this;
        }
        inline float qw() const noexcept {
            return m_qw;
        }
        inline Frame& frameId(const uint32_t &v) noexcept {
            m_frameId = v;
            return *this;
        }
        inline uint32_t frameId() const noexcept {
            return m_frameId;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("x"s), m_x, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("y"s), m_y, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("z"s), m_z, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("float"s), std::move("qx"s), m_qx, visitor);
                return;
            }
            if (5 == fieldId) {
                doVisit(5, std::move("float"s), std::move("qy"s), m_qy, visitor);
                return;
            }
            if (6 == fieldId) {
                doVisit(6, std::move("float"s), std::move("qz"s), m_qz, visitor);
                return;
            }
            if (7 == fieldId) {
                doVisit(7, std::move("float"s), std::move("qw"s), m_qw, visitor);
                return;
            }
            if (8 == fieldId) {
                doVisit(8, std::move("uint32_t"s), std::move("frameId"s), m_frameId, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("x"s), m_x, visitor);
            doVisit(2, std::move("float"s), std::move("y"s), m_y, visitor);
            doVisit(3, std::move("float"s), std::move("z"s), m_z, visitor);
            doVisit(4, std::move("float"s), std::move("qx"s), m_qx, visitor);
            doVisit(5, std::move("float"s), std::move("qy"s), m_qy, visitor);
            doVisit(6, std::move("float"s), std::move("qz"s), m_qz, visitor);
            doVisit(7, std::move("float"s), std::move("qw"s), m_qw, visitor);
            doVisit(8, std::move("uint32_t"s), std::move("frameId"s), m_frameId, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("x"s), m_x, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("y"s), m_y, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("z"s), m_z, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("float"s), std::move("qx"s), m_qx, preVisit, visit, postVisit);
            doTripletForwardVisit(5, std::move("float"s), std::move("qy"s), m_qy, preVisit, visit, postVisit);
            doTripletForwardVisit(6, std::move("float"s), std::move("qz"s), m_qz, preVisit, visit, postVisit);
            doTripletForwardVisit(7, std::move("float"s), std::move("qw"s), m_qw, preVisit, visit, postVisit);
            doTripletForwardVisit(8, std::move("uint32_t"s), std::move("frameId"s), m_frameId, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_x{ 0.0f }; // field identifier = 1.
        float m_y{ 0.0f }; // field identifier = 2.
        float m_z{ 0.0f }; // field identifier = 3.
        float m_qx{ 0.0f }; // field identifier = 4.
        float m_qy{ 0.0f }; // field identifier = 5.
        float m_qz{ 0.0f }; // field identifier = 6.
        float m_qw{ 0.0f }; // field identifier = 7.
        uint32_t m_frameId{ 0 }; // field identifier = 8.
};
}}

template<>
struct isVisitable<opendlv::sim::Frame> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::sim::Frame> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_SIM_COMMAND_HPP
#define OPENDLV_SIM_COMMAND_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace sim {
using namespace std::string_literals; // NOLINT
class LIB_API Command {
    private:
        static constexpr const char* TheShortName = "Command";
        static constexpr const char* TheLongName = "opendlv.sim.Command";

    public:
        inline static int32_t ID() {
            return 1004;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        Command() = default;
        Command(const Command&) = default;
        Command& operator=(const Command&) = default;
        Command(Command&&) = default;
        Command& operator=(Command&&) = default;
        ~Command() = default;

    public:
        inline Command& command(const std::string &v) noexcept {
            m_command = v;
            return *this;
        }
        inline std::string command() const noexcept {
            return m_command;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("std::string"s), std::move("command"s), m_command, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("std::string"s), std::move("command"s), m_command, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("std::string"s), std::move("command"s), m_command, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        std::string m_command{ ""s }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::sim::Command> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::sim::Command> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_META_SAMPLEPROPERTY_HPP
#define OPENDLV_META_SAMPLEPROPERTY_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace meta {
using namespace std::string_literals; // NOLINT
class LIB_API SampleProperty {
    private:
        static constexpr const char* TheShortName = "SampleProperty";
        static constexpr const char* TheLongName = "opendlv.meta.SampleProperty";

    public:
        inline static int32_t ID() {
            return 1010;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        SampleProperty() = default;
        SampleProperty(const SampleProperty&) = default;
        SampleProperty& operator=(const SampleProperty&) = default;
        SampleProperty(SampleProperty&&) = default;
        SampleProperty& operator=(SampleProperty&&) = default;
        ~SampleProperty() = default;

    public:
        inline SampleProperty& key(const std::string &v) noexcept {
            m_key = v;
            return *this;
        }
        inline std::string key() const noexcept {
            return m_key;
        }
        inline SampleProperty& value(const std::string &v) noexcept {
            m_value = v;
            return *this;
        }
        inline std::string value() const noexcept {
            return m_value;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("std::string"s), std::move("key"s), m_key, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("std::string"s), std::move("value"s), m_value, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("std::string"s), std::move("key"s), m_key, visitor);
            doVisit(2, std::move("std::string"s), std::move("value"s), m_value, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("std::string"s), std::move("key"s), m_key, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("std::string"s), std::move("value"s), m_value, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        std::string m_key{ ""s }; // field identifier = 1.
        std::string m_value{ ""s }; // field identifier = 2.
};
}}

template<>
struct isVisitable<opendlv::meta::SampleProperty> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::meta::SampleProperty> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_META_STREAMPROPERTY_HPP
#define OPENDLV_META_STREAMPROPERTY_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace meta {
using namespace std::string_literals; // NOLINT
class LIB_API StreamProperty {
    private:
        static constexpr const char* TheShortName = "StreamProperty";
        static constexpr const char* TheLongName = "opendlv.meta.StreamProperty";

    public:
        inline static int32_t ID() {
            return 1011;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        StreamProperty() = default;
        StreamProperty(const StreamProperty&) = default;
        StreamProperty& operator=(const StreamProperty&) = default;
        StreamProperty(StreamProperty&&) = default;
        StreamProperty& operator=(StreamProperty&&) = default;
        ~StreamProperty() = default;

    public:
        inline StreamProperty& key(const std::string &v) noexcept {
            m_key = v;
            return *this;
        }
        inline std::string key() const noexcept {
            return m_key;
        }
        inline StreamProperty& value(const std::string &v) noexcept {
            m_value = v;
            return *this;
        }
        inline std::string value() const noexcept {
            return m_value;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("std::string"s), std::move("key"s), m_key, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("std::string"s), std::move("value"s), m_value, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("std::string"s), std::move("key"s), m_key, visitor);
            doVisit(2, std::move("std::string"s), std::move("value"s), m_value, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("std::string"s), std::move("key"s), m_key, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("std::string"s), std::move("value"s), m_value, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        std::string m_key{ ""s }; // field identifier = 1.
        std::string m_value{ ""s }; // field identifier = 2.
};
}}

template<>
struct isVisitable<opendlv::meta::StreamProperty> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::meta::StreamProperty> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_META_SUBFRAME_HPP
#define OPENDLV_META_SUBFRAME_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace meta {
using namespace std::string_literals; // NOLINT
class LIB_API SubFrame {
    private:
        static constexpr const char* TheShortName = "SubFrame";
        static constexpr const char* TheLongName = "opendlv.meta.SubFrame";

    public:
        inline static int32_t ID() {
            return 1014;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        SubFrame() = default;
        SubFrame(const SubFrame&) = default;
        SubFrame& operator=(const SubFrame&) = default;
        SubFrame(SubFrame&&) = default;
        SubFrame& operator=(SubFrame&&) = default;
        ~SubFrame() = default;

    public:
        inline SubFrame& x(const float &v) noexcept {
            m_x = v;
            return *this;
        }
        inline float x() const noexcept {
            return m_x;
        }
        inline SubFrame& y(const float &v) noexcept {
            m_y = v;
            return *this;
        }
        inline float y() const noexcept {
            return m_y;
        }
        inline SubFrame& z(const float &v) noexcept {
            m_z = v;
            return *this;
        }
        inline float z() const noexcept {
            return m_z;
        }
        inline SubFrame& qx(const float &v) noexcept {
            m_qx = v;
            return *this;
        }
        inline float qx() const noexcept {
            return m_qx;
        }
        inline SubFrame& qy(const float &v) noexcept {
            m_qy = v;
            return *this;
        }
        inline float qy() const noexcept {
            return m_qy;
        }
        inline SubFrame& qz(const float &v) noexcept {
            m_qz = v;
            return *this;
        }
        inline float qz() const noexcept {
            return m_qz;
        }
        inline SubFrame& qw(const float &v) noexcept {
            m_qw = v;
            return *this;
        }
        inline float qw() const noexcept {
            return m_qw;
        }
        inline SubFrame& frameId(const uint32_t &v) noexcept {
            m_frameId = v;
            return *this;
        }
        inline uint32_t frameId() const noexcept {
            return m_frameId;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("x"s), m_x, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("y"s), m_y, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("z"s), m_z, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("float"s), std::move("qx"s), m_qx, visitor);
                return;
            }
            if (5 == fieldId) {
                doVisit(5, std::move("float"s), std::move("qy"s), m_qy, visitor);
                return;
            }
            if (6 == fieldId) {
                doVisit(6, std::move("float"s), std::move("qz"s), m_qz, visitor);
                return;
            }
            if (7 == fieldId) {
                doVisit(7, std::move("float"s), std::move("qw"s), m_qw, visitor);
                return;
            }
            if (8 == fieldId) {
                doVisit(8, std::move("uint32_t"s), std::move("frameId"s), m_frameId, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("x"s), m_x, visitor);
            doVisit(2, std::move("float"s), std::move("y"s), m_y, visitor);
            doVisit(3, std::move("float"s), std::move("z"s), m_z, visitor);
            doVisit(4, std::move("float"s), std::move("qx"s), m_qx, visitor);
            doVisit(5, std::move("float"s), std::move("qy"s), m_qy, visitor);
            doVisit(6, std::move("float"s), std::move("qz"s), m_qz, visitor);
            doVisit(7, std::move("float"s), std::move("qw"s), m_qw, visitor);
            doVisit(8, std::move("uint32_t"s), std::move("frameId"s), m_frameId, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("x"s), m_x, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("y"s), m_y, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("z"s), m_z, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("float"s), std::move("qx"s), m_qx, preVisit, visit, postVisit);
            doTripletForwardVisit(5, std::move("float"s), std::move("qy"s), m_qy, preVisit, visit, postVisit);
            doTripletForwardVisit(6, std::move("float"s), std::move("qz"s), m_qz, preVisit, visit, postVisit);
            doTripletForwardVisit(7, std::move("float"s), std::move("qw"s), m_qw, preVisit, visit, postVisit);
            doTripletForwardVisit(8, std::move("uint32_t"s), std::move("frameId"s), m_frameId, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_x{ 0.0f }; // field identifier = 1.
        float m_y{ 0.0f }; // field identifier = 2.
        float m_z{ 0.0f }; // field identifier = 3.
        float m_qx{ 0.0f }; // field identifier = 4.
        float m_qy{ 0.0f }; // field identifier = 5.
        float m_qz{ 0.0f }; // field identifier = 6.
        float m_qw{ 0.0f }; // field identifier = 7.
        uint32_t m_frameId{ 0 }; // field identifier = 8.
};
}}

template<>
struct isVisitable<opendlv::meta::SubFrame> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::meta::SubFrame> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_META_CALIBRATIONVISUALDISTORTION_HPP
#define OPENDLV_META_CALIBRATIONVISUALDISTORTION_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace meta {
using namespace std::string_literals; // NOLINT
class LIB_API CalibrationVisualDistortion {
    private:
        static constexpr const char* TheShortName = "CalibrationVisualDistortion";
        static constexpr const char* TheLongName = "opendlv.meta.CalibrationVisualDistortion";

    public:
        inline static int32_t ID() {
            return 1015;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        CalibrationVisualDistortion() = default;
        CalibrationVisualDistortion(const CalibrationVisualDistortion&) = default;
        CalibrationVisualDistortion& operator=(const CalibrationVisualDistortion&) = default;
        CalibrationVisualDistortion(CalibrationVisualDistortion&&) = default;
        CalibrationVisualDistortion& operator=(CalibrationVisualDistortion&&) = default;
        ~CalibrationVisualDistortion() = default;

    public:
        inline CalibrationVisualDistortion& k1(const float &v) noexcept {
            m_k1 = v;
            return *this;
        }
        inline float k1() const noexcept {
            return m_k1;
        }
        inline CalibrationVisualDistortion& k2(const float &v) noexcept {
            m_k2 = v;
            return *this;
        }
        inline float k2() const noexcept {
            return m_k2;
        }
        inline CalibrationVisualDistortion& k3(const float &v) noexcept {
            m_k3 = v;
            return *this;
        }
        inline float k3() const noexcept {
            return m_k3;
        }
        inline CalibrationVisualDistortion& p1(const float &v) noexcept {
            m_p1 = v;
            return *this;
        }
        inline float p1() const noexcept {
            return m_p1;
        }
        inline CalibrationVisualDistortion& p2(const float &v) noexcept {
            m_p2 = v;
            return *this;
        }
        inline float p2() const noexcept {
            return m_p2;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("k1"s), m_k1, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("k2"s), m_k2, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("k3"s), m_k3, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("float"s), std::move("p1"s), m_p1, visitor);
                return;
            }
            if (5 == fieldId) {
                doVisit(5, std::move("float"s), std::move("p2"s), m_p2, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("k1"s), m_k1, visitor);
            doVisit(2, std::move("float"s), std::move("k2"s), m_k2, visitor);
            doVisit(3, std::move("float"s), std::move("k3"s), m_k3, visitor);
            doVisit(4, std::move("float"s), std::move("p1"s), m_p1, visitor);
            doVisit(5, std::move("float"s), std::move("p2"s), m_p2, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("k1"s), m_k1, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("k2"s), m_k2, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("k3"s), m_k3, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("float"s), std::move("p1"s), m_p1, preVisit, visit, postVisit);
            doTripletForwardVisit(5, std::move("float"s), std::move("p2"s), m_p2, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_k1{ 0.0f }; // field identifier = 1.
        float m_k2{ 0.0f }; // field identifier = 2.
        float m_k3{ 0.0f }; // field identifier = 3.
        float m_p1{ 0.0f }; // field identifier = 4.
        float m_p2{ 0.0f }; // field identifier = 5.
};
}}

template<>
struct isVisitable<opendlv::meta::CalibrationVisualDistortion> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::meta::CalibrationVisualDistortion> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_META_CALIBRATIONCAMERAINTRINSIC_HPP
#define OPENDLV_META_CALIBRATIONCAMERAINTRINSIC_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace meta {
using namespace std::string_literals; // NOLINT
class LIB_API CalibrationCameraIntrinsic {
    private:
        static constexpr const char* TheShortName = "CalibrationCameraIntrinsic";
        static constexpr const char* TheLongName = "opendlv.meta.CalibrationCameraIntrinsic";

    public:
        inline static int32_t ID() {
            return 1016;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        CalibrationCameraIntrinsic() = default;
        CalibrationCameraIntrinsic(const CalibrationCameraIntrinsic&) = default;
        CalibrationCameraIntrinsic& operator=(const CalibrationCameraIntrinsic&) = default;
        CalibrationCameraIntrinsic(CalibrationCameraIntrinsic&&) = default;
        CalibrationCameraIntrinsic& operator=(CalibrationCameraIntrinsic&&) = default;
        ~CalibrationCameraIntrinsic() = default;

    public:
        inline CalibrationCameraIntrinsic& fx(const float &v) noexcept {
            m_fx = v;
            return *this;
        }
        inline float fx() const noexcept {
            return m_fx;
        }
        inline CalibrationCameraIntrinsic& fy(const float &v) noexcept {
            m_fy = v;
            return *this;
        }
        inline float fy() const noexcept {
            return m_fy;
        }
        inline CalibrationCameraIntrinsic& cx(const float &v) noexcept {
            m_cx = v;
            return *this;
        }
        inline float cx() const noexcept {
            return m_cx;
        }
        inline CalibrationCameraIntrinsic& cy(const float &v) noexcept {
            m_cy = v;
            return *this;
        }
        inline float cy() const noexcept {
            return m_cy;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("fx"s), m_fx, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("fy"s), m_fy, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("cx"s), m_cx, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("float"s), std::move("cy"s), m_cy, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("fx"s), m_fx, visitor);
            doVisit(2, std::move("float"s), std::move("fy"s), m_fy, visitor);
            doVisit(3, std::move("float"s), std::move("cx"s), m_cx, visitor);
            doVisit(4, std::move("float"s), std::move("cy"s), m_cy, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("fx"s), m_fx, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("fy"s), m_fy, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("cx"s), m_cx, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("float"s), std::move("cy"s), m_cy, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_fx{ 0.0f }; // field identifier = 1.
        float m_fy{ 0.0f }; // field identifier = 2.
        float m_cx{ 0.0f }; // field identifier = 3.
        float m_cy{ 0.0f }; // field identifier = 4.
};
}}

template<>
struct isVisitable<opendlv::meta::CalibrationCameraIntrinsic> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::meta::CalibrationCameraIntrinsic> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_META_CALIBRATIONEXTRINSIC_HPP
#define OPENDLV_META_CALIBRATIONEXTRINSIC_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace meta {
using namespace std::string_literals; // NOLINT
class LIB_API CalibrationExtrinsic {
    private:
        static constexpr const char* TheShortName = "CalibrationExtrinsic";
        static constexpr const char* TheLongName = "opendlv.meta.CalibrationExtrinsic";

    public:
        inline static int32_t ID() {
            return 1017;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        CalibrationExtrinsic() = default;
        CalibrationExtrinsic(const CalibrationExtrinsic&) = default;
        CalibrationExtrinsic& operator=(const CalibrationExtrinsic&) = default;
        CalibrationExtrinsic(CalibrationExtrinsic&&) = default;
        CalibrationExtrinsic& operator=(CalibrationExtrinsic&&) = default;
        ~CalibrationExtrinsic() = default;

    public:
        inline CalibrationExtrinsic& x(const float &v) noexcept {
            m_x = v;
            return *this;
        }
        inline float x() const noexcept {
            return m_x;
        }
        inline CalibrationExtrinsic& y(const float &v) noexcept {
            m_y = v;
            return *this;
        }
        inline float y() const noexcept {
            return m_y;
        }
        inline CalibrationExtrinsic& z(const float &v) noexcept {
            m_z = v;
            return *this;
        }
        inline float z() const noexcept {
            return m_z;
        }
        inline CalibrationExtrinsic& qx(const float &v) noexcept {
            m_qx = v;
            return *this;
        }
        inline float qx() const noexcept {
            return m_qx;
        }
        inline CalibrationExtrinsic& qy(const float &v) noexcept {
            m_qy = v;
            return *this;
        }
        inline float qy() const noexcept {
            return m_qy;
        }
        inline CalibrationExtrinsic& qz(const float &v) noexcept {
            m_qz = v;
            return *this;
        }
        inline float qz() const noexcept {
            return m_qz;
        }
        inline CalibrationExtrinsic& qw(const float &v) noexcept {
            m_qw = v;
            return *this;
        }
        inline float qw() const noexcept {
            return m_qw;
        }
        inline CalibrationExtrinsic& frameId(const uint32_t &v) noexcept {
            m_frameId = v;
            return *this;
        }
        inline uint32_t frameId() const noexcept {
            return m_frameId;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("x"s), m_x, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("y"s), m_y, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("z"s), m_z, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("float"s), std::move("qx"s), m_qx, visitor);
                return;
            }
            if (5 == fieldId) {
                doVisit(5, std::move("float"s), std::move("qy"s), m_qy, visitor);
                return;
            }
            if (6 == fieldId) {
                doVisit(6, std::move("float"s), std::move("qz"s), m_qz, visitor);
                return;
            }
            if (7 == fieldId) {
                doVisit(7, std::move("float"s), std::move("qw"s), m_qw, visitor);
                return;
            }
            if (8 == fieldId) {
                doVisit(8, std::move("uint32_t"s), std::move("frameId"s), m_frameId, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("x"s), m_x, visitor);
            doVisit(2, std::move("float"s), std::move("y"s), m_y, visitor);
            doVisit(3, std::move("float"s), std::move("z"s), m_z, visitor);
            doVisit(4, std::move("float"s), std::move("qx"s), m_qx, visitor);
            doVisit(5, std::move("float"s), std::move("qy"s), m_qy, visitor);
            doVisit(6, std::move("float"s), std::move("qz"s), m_qz, visitor);
            doVisit(7, std::move("float"s), std::move("qw"s), m_qw, visitor);
            doVisit(8, std::move("uint32_t"s), std::move("frameId"s), m_frameId, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("x"s), m_x, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("y"s), m_y, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("z"s), m_z, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("float"s), std::move("qx"s), m_qx, preVisit, visit, postVisit);
            doTripletForwardVisit(5, std::move("float"s), std::move("qy"s), m_qy, preVisit, visit, postVisit);
            doTripletForwardVisit(6, std::move("float"s), std::move("qz"s), m_qz, preVisit, visit, postVisit);
            doTripletForwardVisit(7, std::move("float"s), std::move("qw"s), m_qw, preVisit, visit, postVisit);
            doTripletForwardVisit(8, std::move("uint32_t"s), std::move("frameId"s), m_frameId, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_x{ 0.0f }; // field identifier = 1.
        float m_y{ 0.0f }; // field identifier = 2.
        float m_z{ 0.0f }; // field identifier = 3.
        float m_qx{ 0.0f }; // field identifier = 4.
        float m_qy{ 0.0f }; // field identifier = 5.
        float m_qz{ 0.0f }; // field identifier = 6.
        float m_qw{ 0.0f }; // field identifier = 7.
        uint32_t m_frameId{ 0 }; // field identifier = 8.
};
}}

template<>
struct isVisitable<opendlv::meta::CalibrationExtrinsic> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::meta::CalibrationExtrinsic> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_META_FRAMESHAPESHM_HPP
#define OPENDLV_META_FRAMESHAPESHM_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace meta {
using namespace std::string_literals; // NOLINT
class LIB_API FrameShapeShm {
    private:
        static constexpr const char* TheShortName = "FrameShapeShm";
        static constexpr const char* TheLongName = "opendlv.meta.FrameShapeShm";

    public:
        inline static int32_t ID() {
            return 1020;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        FrameShapeShm() = default;
        FrameShapeShm(const FrameShapeShm&) = default;
        FrameShapeShm& operator=(const FrameShapeShm&) = default;
        FrameShapeShm(FrameShapeShm&&) = default;
        FrameShapeShm& operator=(FrameShapeShm&&) = default;
        ~FrameShapeShm() = default;

    public:
        inline FrameShapeShm& format(const std::string &v) noexcept {
            m_format = v;
            return *this;
        }
        inline std::string format() const noexcept {
            return m_format;
        }
        inline FrameShapeShm& location(const std::string &v) noexcept {
            m_location = v;
            return *this;
        }
        inline std::string location() const noexcept {
            return m_location;
        }
        inline FrameShapeShm& frameId(const uint32_t &v) noexcept {
            m_frameId = v;
            return *this;
        }
        inline uint32_t frameId() const noexcept {
            return m_frameId;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("std::string"s), std::move("format"s), m_format, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("std::string"s), std::move("location"s), m_location, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("uint32_t"s), std::move("frameId"s), m_frameId, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("std::string"s), std::move("format"s), m_format, visitor);
            doVisit(2, std::move("std::string"s), std::move("location"s), m_location, visitor);
            doVisit(3, std::move("uint32_t"s), std::move("frameId"s), m_frameId, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("std::string"s), std::move("format"s), m_format, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("std::string"s), std::move("location"s), m_location, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("uint32_t"s), std::move("frameId"s), m_frameId, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        std::string m_format{ ""s }; // field identifier = 1.
        std::string m_location{ ""s }; // field identifier = 2.
        uint32_t m_frameId{ 0 }; // field identifier = 3.
};
}}

template<>
struct isVisitable<opendlv::meta::FrameShapeShm> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::meta::FrameShapeShm> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_META_FRAMESHAPE_HPP
#define OPENDLV_META_FRAMESHAPE_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace meta {
using namespace std::string_literals; // NOLINT
class LIB_API FrameShape {
    private:
        static constexpr const char* TheShortName = "FrameShape";
        static constexpr const char* TheLongName = "opendlv.meta.FrameShape";

    public:
        inline static int32_t ID() {
            return 1021;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        FrameShape() = default;
        FrameShape(const FrameShape&) = default;
        FrameShape& operator=(const FrameShape&) = default;
        FrameShape(FrameShape&&) = default;
        FrameShape& operator=(FrameShape&&) = default;
        ~FrameShape() = default;

    public:
        inline FrameShape& format(const std::string &v) noexcept {
            m_format = v;
            return *this;
        }
        inline std::string format() const noexcept {
            return m_format;
        }
        inline FrameShape& data(const std::string &v) noexcept {
            m_data = v;
            return *this;
        }
        inline std::string data() const noexcept {
            return m_data;
        }
        inline FrameShape& frameId(const uint32_t &v) noexcept {
            m_frameId = v;
            return *this;
        }
        inline uint32_t frameId() const noexcept {
            return m_frameId;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("std::string"s), std::move("format"s), m_format, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("std::string"s), std::move("data"s), m_data, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("uint32_t"s), std::move("frameId"s), m_frameId, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("std::string"s), std::move("format"s), m_format, visitor);
            doVisit(2, std::move("std::string"s), std::move("data"s), m_data, visitor);
            doVisit(3, std::move("uint32_t"s), std::move("frameId"s), m_frameId, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("std::string"s), std::move("format"s), m_format, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("std::string"s), std::move("data"s), m_data, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("uint32_t"s), std::move("frameId"s), m_frameId, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        std::string m_format{ ""s }; // field identifier = 1.
        std::string m_data{ ""s }; // field identifier = 2.
        uint32_t m_frameId{ 0 }; // field identifier = 3.
};
}}

template<>
struct isVisitable<opendlv::meta::FrameShape> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::meta::FrameShape> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_STEPREADING_HPP
#define OPENDLV_PROXY_STEPREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API StepReading {
    private:
        static constexpr const char* TheShortName = "StepReading";
        static constexpr const char* TheLongName = "opendlv.proxy.StepReading";

    public:
        inline static int32_t ID() {
            return 1029;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        StepReading() = default;
        StepReading(const StepReading&) = default;
        StepReading& operator=(const StepReading&) = default;
        StepReading(StepReading&&) = default;
        StepReading& operator=(StepReading&&) = default;
        ~StepReading() = default;

    public:
        inline StepReading& steps(const int32_t &v) noexcept {
            m_steps = v;
            return *this;
        }
        inline int32_t steps() const noexcept {
            return m_steps;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("int32_t"s), std::move("steps"s), m_steps, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("int32_t"s), std::move("steps"s), m_steps, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("int32_t"s), std::move("steps"s), m_steps, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        int32_t m_steps{ 0 }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::StepReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::StepReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_ACCELERATIONREADING_HPP
#define OPENDLV_PROXY_ACCELERATIONREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API AccelerationReading {
    private:
        static constexpr const char* TheShortName = "AccelerationReading";
        static constexpr const char* TheLongName = "opendlv.proxy.AccelerationReading";

    public:
        inline static int32_t ID() {
            return 1030;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        AccelerationReading() = default;
        AccelerationReading(const AccelerationReading&) = default;
        AccelerationReading& operator=(const AccelerationReading&) = default;
        AccelerationReading(AccelerationReading&&) = default;
        AccelerationReading& operator=(AccelerationReading&&) = default;
        ~AccelerationReading() = default;

    public:
        inline AccelerationReading& accelerationX(const float &v) noexcept {
            m_accelerationX = v;
            return *this;
        }
        inline float accelerationX() const noexcept {
            return m_accelerationX;
        }
        inline AccelerationReading& accelerationY(const float &v) noexcept {
            m_accelerationY = v;
            return *this;
        }
        inline float accelerationY() const noexcept {
            return m_accelerationY;
        }
        inline AccelerationReading& accelerationZ(const float &v) noexcept {
            m_accelerationZ = v;
            return *this;
        }
        inline float accelerationZ() const noexcept {
            return m_accelerationZ;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("accelerationX"s), m_accelerationX, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("accelerationY"s), m_accelerationY, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("accelerationZ"s), m_accelerationZ, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("accelerationX"s), m_accelerationX, visitor);
            doVisit(2, std::move("float"s), std::move("accelerationY"s), m_accelerationY, visitor);
            doVisit(3, std::move("float"s), std::move("accelerationZ"s), m_accelerationZ, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("accelerationX"s), m_accelerationX, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("accelerationY"s), m_accelerationY, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("accelerationZ"s), m_accelerationZ, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_accelerationX{ 0.0f }; // field identifier = 1.
        float m_accelerationY{ 0.0f }; // field identifier = 2.
        float m_accelerationZ{ 0.0f }; // field identifier = 3.
};
}}

template<>
struct isVisitable<opendlv::proxy::AccelerationReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::AccelerationReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_ANGULARVELOCITYREADING_HPP
#define OPENDLV_PROXY_ANGULARVELOCITYREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API AngularVelocityReading {
    private:
        static constexpr const char* TheShortName = "AngularVelocityReading";
        static constexpr const char* TheLongName = "opendlv.proxy.AngularVelocityReading";

    public:
        inline static int32_t ID() {
            return 1031;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        AngularVelocityReading() = default;
        AngularVelocityReading(const AngularVelocityReading&) = default;
        AngularVelocityReading& operator=(const AngularVelocityReading&) = default;
        AngularVelocityReading(AngularVelocityReading&&) = default;
        AngularVelocityReading& operator=(AngularVelocityReading&&) = default;
        ~AngularVelocityReading() = default;

    public:
        inline AngularVelocityReading& angularVelocityX(const float &v) noexcept {
            m_angularVelocityX = v;
            return *this;
        }
        inline float angularVelocityX() const noexcept {
            return m_angularVelocityX;
        }
        inline AngularVelocityReading& angularVelocityY(const float &v) noexcept {
            m_angularVelocityY = v;
            return *this;
        }
        inline float angularVelocityY() const noexcept {
            return m_angularVelocityY;
        }
        inline AngularVelocityReading& angularVelocityZ(const float &v) noexcept {
            m_angularVelocityZ = v;
            return *this;
        }
        inline float angularVelocityZ() const noexcept {
            return m_angularVelocityZ;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("angularVelocityX"s), m_angularVelocityX, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("angularVelocityY"s), m_angularVelocityY, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("angularVelocityZ"s), m_angularVelocityZ, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("angularVelocityX"s), m_angularVelocityX, visitor);
            doVisit(2, std::move("float"s), std::move("angularVelocityY"s), m_angularVelocityY, visitor);
            doVisit(3, std::move("float"s), std::move("angularVelocityZ"s), m_angularVelocityZ, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("angularVelocityX"s), m_angularVelocityX, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("angularVelocityY"s), m_angularVelocityY, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("angularVelocityZ"s), m_angularVelocityZ, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_angularVelocityX{ 0.0f }; // field identifier = 1.
        float m_angularVelocityY{ 0.0f }; // field identifier = 2.
        float m_angularVelocityZ{ 0.0f }; // field identifier = 3.
};
}}

template<>
struct isVisitable<opendlv::proxy::AngularVelocityReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::AngularVelocityReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_MAGNETICFIELDREADING_HPP
#define OPENDLV_PROXY_MAGNETICFIELDREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API MagneticFieldReading {
    private:
        static constexpr const char* TheShortName = "MagneticFieldReading";
        static constexpr const char* TheLongName = "opendlv.proxy.MagneticFieldReading";

    public:
        inline static int32_t ID() {
            return 1032;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        MagneticFieldReading() = default;
        MagneticFieldReading(const MagneticFieldReading&) = default;
        MagneticFieldReading& operator=(const MagneticFieldReading&) = default;
        MagneticFieldReading(MagneticFieldReading&&) = default;
        MagneticFieldReading& operator=(MagneticFieldReading&&) = default;
        ~MagneticFieldReading() = default;

    public:
        inline MagneticFieldReading& magneticFieldX(const float &v) noexcept {
            m_magneticFieldX = v;
            return *this;
        }
        inline float magneticFieldX() const noexcept {
            return m_magneticFieldX;
        }
        inline MagneticFieldReading& magneticFieldY(const float &v) noexcept {
            m_magneticFieldY = v;
            return *this;
        }
        inline float magneticFieldY() const noexcept {
            return m_magneticFieldY;
        }
        inline MagneticFieldReading& magneticFieldZ(const float &v) noexcept {
            m_magneticFieldZ = v;
            return *this;
        }
        inline float magneticFieldZ() const noexcept {
            return m_magneticFieldZ;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("magneticFieldX"s), m_magneticFieldX, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("magneticFieldY"s), m_magneticFieldY, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("magneticFieldZ"s), m_magneticFieldZ, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("magneticFieldX"s), m_magneticFieldX, visitor);
            doVisit(2, std::move("float"s), std::move("magneticFieldY"s), m_magneticFieldY, visitor);
            doVisit(3, std::move("float"s), std::move("magneticFieldZ"s), m_magneticFieldZ, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("magneticFieldX"s), m_magneticFieldX, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("magneticFieldY"s), m_magneticFieldY, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("magneticFieldZ"s), m_magneticFieldZ, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_magneticFieldX{ 0.0f }; // field identifier = 1.
        float m_magneticFieldY{ 0.0f }; // field identifier = 2.
        float m_magneticFieldZ{ 0.0f }; // field identifier = 3.
};
}}

template<>
struct isVisitable<opendlv::proxy::MagneticFieldReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::MagneticFieldReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_ALTITUDEREADING_HPP
#define OPENDLV_PROXY_ALTITUDEREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API AltitudeReading {
    private:
        static constexpr const char* TheShortName = "AltitudeReading";
        static constexpr const char* TheLongName = "opendlv.proxy.AltitudeReading";

    public:
        inline static int32_t ID() {
            return 1033;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        AltitudeReading() = default;
        AltitudeReading(const AltitudeReading&) = default;
        AltitudeReading& operator=(const AltitudeReading&) = default;
        AltitudeReading(AltitudeReading&&) = default;
        AltitudeReading& operator=(AltitudeReading&&) = default;
        ~AltitudeReading() = default;

    public:
        inline AltitudeReading& altitude(const float &v) noexcept {
            m_altitude = v;
            return *this;
        }
        inline float altitude() const noexcept {
            return m_altitude;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("altitude"s), m_altitude, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("altitude"s), m_altitude, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("altitude"s), m_altitude, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_altitude{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::AltitudeReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::AltitudeReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_PRESSUREREADING_HPP
#define OPENDLV_PROXY_PRESSUREREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API PressureReading {
    private:
        static constexpr const char* TheShortName = "PressureReading";
        static constexpr const char* TheLongName = "opendlv.proxy.PressureReading";

    public:
        inline static int32_t ID() {
            return 1034;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        PressureReading() = default;
        PressureReading(const PressureReading&) = default;
        PressureReading& operator=(const PressureReading&) = default;
        PressureReading(PressureReading&&) = default;
        PressureReading& operator=(PressureReading&&) = default;
        ~PressureReading() = default;

    public:
        inline PressureReading& pressure(const float &v) noexcept {
            m_pressure = v;
            return *this;
        }
        inline float pressure() const noexcept {
            return m_pressure;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("pressure"s), m_pressure, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("pressure"s), m_pressure, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("pressure"s), m_pressure, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_pressure{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::PressureReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::PressureReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_TEMPERATUREREADING_HPP
#define OPENDLV_PROXY_TEMPERATUREREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API TemperatureReading {
    private:
        static constexpr const char* TheShortName = "TemperatureReading";
        static constexpr const char* TheLongName = "opendlv.proxy.TemperatureReading";

    public:
        inline static int32_t ID() {
            return 1035;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        TemperatureReading() = default;
        TemperatureReading(const TemperatureReading&) = default;
        TemperatureReading& operator=(const TemperatureReading&) = default;
        TemperatureReading(TemperatureReading&&) = default;
        TemperatureReading& operator=(TemperatureReading&&) = default;
        ~TemperatureReading() = default;

    public:
        inline TemperatureReading& temperature(const float &v) noexcept {
            m_temperature = v;
            return *this;
        }
        inline float temperature() const noexcept {
            return m_temperature;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("temperature"s), m_temperature, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("temperature"s), m_temperature, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("temperature"s), m_temperature, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_temperature{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::TemperatureReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::TemperatureReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_TORQUEREADING_HPP
#define OPENDLV_PROXY_TORQUEREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API TorqueReading {
    private:
        static constexpr const char* TheShortName = "TorqueReading";
        static constexpr const char* TheLongName = "opendlv.proxy.TorqueReading";

    public:
        inline static int32_t ID() {
            return 1036;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        TorqueReading() = default;
        TorqueReading(const TorqueReading&) = default;
        TorqueReading& operator=(const TorqueReading&) = default;
        TorqueReading(TorqueReading&&) = default;
        TorqueReading& operator=(TorqueReading&&) = default;
        ~TorqueReading() = default;

    public:
        inline TorqueReading& torque(const float &v) noexcept {
            m_torque = v;
            return *this;
        }
        inline float torque() const noexcept {
            return m_torque;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("torque"s), m_torque, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("torque"s), m_torque, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("torque"s), m_torque, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_torque{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::TorqueReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::TorqueReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_VOLTAGEREADING_HPP
#define OPENDLV_PROXY_VOLTAGEREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API VoltageReading {
    private:
        static constexpr const char* TheShortName = "VoltageReading";
        static constexpr const char* TheLongName = "opendlv.proxy.VoltageReading";

    public:
        inline static int32_t ID() {
            return 1037;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        VoltageReading() = default;
        VoltageReading(const VoltageReading&) = default;
        VoltageReading& operator=(const VoltageReading&) = default;
        VoltageReading(VoltageReading&&) = default;
        VoltageReading& operator=(VoltageReading&&) = default;
        ~VoltageReading() = default;

    public:
        inline VoltageReading& voltage(const float &v) noexcept {
            m_voltage = v;
            return *this;
        }
        inline float voltage() const noexcept {
            return m_voltage;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("voltage"s), m_voltage, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("voltage"s), m_voltage, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("voltage"s), m_voltage, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_voltage{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::VoltageReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::VoltageReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_ANGLEREADING_HPP
#define OPENDLV_PROXY_ANGLEREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API AngleReading {
    private:
        static constexpr const char* TheShortName = "AngleReading";
        static constexpr const char* TheLongName = "opendlv.proxy.AngleReading";

    public:
        inline static int32_t ID() {
            return 1038;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        AngleReading() = default;
        AngleReading(const AngleReading&) = default;
        AngleReading& operator=(const AngleReading&) = default;
        AngleReading(AngleReading&&) = default;
        AngleReading& operator=(AngleReading&&) = default;
        ~AngleReading() = default;

    public:
        inline AngleReading& angle(const float &v) noexcept {
            m_angle = v;
            return *this;
        }
        inline float angle() const noexcept {
            return m_angle;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("angle"s), m_angle, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("angle"s), m_angle, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("angle"s), m_angle, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_angle{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::AngleReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::AngleReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_DISTANCEREADING_HPP
#define OPENDLV_PROXY_DISTANCEREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API DistanceReading {
    private:
        static constexpr const char* TheShortName = "DistanceReading";
        static constexpr const char* TheLongName = "opendlv.proxy.DistanceReading";

    public:
        inline static int32_t ID() {
            return 1039;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        DistanceReading() = default;
        DistanceReading(const DistanceReading&) = default;
        DistanceReading& operator=(const DistanceReading&) = default;
        DistanceReading(DistanceReading&&) = default;
        DistanceReading& operator=(DistanceReading&&) = default;
        ~DistanceReading() = default;

    public:
        inline DistanceReading& distance(const float &v) noexcept {
            m_distance = v;
            return *this;
        }
        inline float distance() const noexcept {
            return m_distance;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("distance"s), m_distance, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("distance"s), m_distance, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("distance"s), m_distance, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_distance{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::DistanceReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::DistanceReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_SWITCHSTATEREADING_HPP
#define OPENDLV_PROXY_SWITCHSTATEREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API SwitchStateReading {
    private:
        static constexpr const char* TheShortName = "SwitchStateReading";
        static constexpr const char* TheLongName = "opendlv.proxy.SwitchStateReading";

    public:
        inline static int32_t ID() {
            return 1040;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        SwitchStateReading() = default;
        SwitchStateReading(const SwitchStateReading&) = default;
        SwitchStateReading& operator=(const SwitchStateReading&) = default;
        SwitchStateReading(SwitchStateReading&&) = default;
        SwitchStateReading& operator=(SwitchStateReading&&) = default;
        ~SwitchStateReading() = default;

    public:
        inline SwitchStateReading& state(const int16_t &v) noexcept {
            m_state = v;
            return *this;
        }
        inline int16_t state() const noexcept {
            return m_state;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("int16_t"s), std::move("state"s), m_state, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("int16_t"s), std::move("state"s), m_state, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("int16_t"s), std::move("state"s), m_state, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        int16_t m_state{ 0 }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::SwitchStateReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::SwitchStateReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_PEDALPOSITIONREADING_HPP
#define OPENDLV_PROXY_PEDALPOSITIONREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API PedalPositionReading {
    private:
        static constexpr const char* TheShortName = "PedalPositionReading";
        static constexpr const char* TheLongName = "opendlv.proxy.PedalPositionReading";

    public:
        inline static int32_t ID() {
            return 1041;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        PedalPositionReading() = default;
        PedalPositionReading(const PedalPositionReading&) = default;
        PedalPositionReading& operator=(const PedalPositionReading&) = default;
        PedalPositionReading(PedalPositionReading&&) = default;
        PedalPositionReading& operator=(PedalPositionReading&&) = default;
        ~PedalPositionReading() = default;

    public:
        inline PedalPositionReading& position(const float &v) noexcept {
            m_position = v;
            return *this;
        }
        inline float position() const noexcept {
            return m_position;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("position"s), m_position, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("position"s), m_position, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("position"s), m_position, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_position{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::PedalPositionReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::PedalPositionReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_ELECTRICCURRENTREADING_HPP
#define OPENDLV_PROXY_ELECTRICCURRENTREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API ElectricCurrentReading {
    private:
        static constexpr const char* TheShortName = "ElectricCurrentReading";
        static constexpr const char* TheLongName = "opendlv.proxy.ElectricCurrentReading";

    public:
        inline static int32_t ID() {
            return 1042;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        ElectricCurrentReading() = default;
        ElectricCurrentReading(const ElectricCurrentReading&) = default;
        ElectricCurrentReading& operator=(const ElectricCurrentReading&) = default;
        ElectricCurrentReading(ElectricCurrentReading&&) = default;
        ElectricCurrentReading& operator=(ElectricCurrentReading&&) = default;
        ~ElectricCurrentReading() = default;

    public:
        inline ElectricCurrentReading& electricCurrent(const float &v) noexcept {
            m_electricCurrent = v;
            return *this;
        }
        inline float electricCurrent() const noexcept {
            return m_electricCurrent;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("electricCurrent"s), m_electricCurrent, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("electricCurrent"s), m_electricCurrent, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("electricCurrent"s), m_electricCurrent, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_electricCurrent{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::ElectricCurrentReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::ElectricCurrentReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_STATEOFCHARGEREADING_HPP
#define OPENDLV_PROXY_STATEOFCHARGEREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API StateOfChargeReading {
    private:
        static constexpr const char* TheShortName = "StateOfChargeReading";
        static constexpr const char* TheLongName = "opendlv.proxy.StateOfChargeReading";

    public:
        inline static int32_t ID() {
            return 1043;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        StateOfChargeReading() = default;
        StateOfChargeReading(const StateOfChargeReading&) = default;
        StateOfChargeReading& operator=(const StateOfChargeReading&) = default;
        StateOfChargeReading(StateOfChargeReading&&) = default;
        StateOfChargeReading& operator=(StateOfChargeReading&&) = default;
        ~StateOfChargeReading() = default;

    public:
        inline StateOfChargeReading& stateOfCharge(const float &v) noexcept {
            m_stateOfCharge = v;
            return *this;
        }
        inline float stateOfCharge() const noexcept {
            return m_stateOfCharge;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("stateOfCharge"s), m_stateOfCharge, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("stateOfCharge"s), m_stateOfCharge, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("stateOfCharge"s), m_stateOfCharge, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_stateOfCharge{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::StateOfChargeReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::StateOfChargeReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_GROUNDSTEERINGREADING_HPP
#define OPENDLV_PROXY_GROUNDSTEERINGREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API GroundSteeringReading {
    private:
        static constexpr const char* TheShortName = "GroundSteeringReading";
        static constexpr const char* TheLongName = "opendlv.proxy.GroundSteeringReading";

    public:
        inline static int32_t ID() {
            return 1045;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        GroundSteeringReading() = default;
        GroundSteeringReading(const GroundSteeringReading&) = default;
        GroundSteeringReading& operator=(const GroundSteeringReading&) = default;
        GroundSteeringReading(GroundSteeringReading&&) = default;
        GroundSteeringReading& operator=(GroundSteeringReading&&) = default;
        ~GroundSteeringReading() = default;

    public:
        inline GroundSteeringReading& groundSteering(const float &v) noexcept {
            m_groundSteering = v;
            return *this;
        }
        inline float groundSteering() const noexcept {
            return m_groundSteering;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("groundSteering"s), m_groundSteering, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("groundSteering"s), m_groundSteering, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("groundSteering"s), m_groundSteering, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_groundSteering{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::GroundSteeringReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::GroundSteeringReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_GROUNDSPEEDREADING_HPP
#define OPENDLV_PROXY_GROUNDSPEEDREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API GroundSpeedReading {
    private:
        static constexpr const char* TheShortName = "GroundSpeedReading";
        static constexpr const char* TheLongName = "opendlv.proxy.GroundSpeedReading";

    public:
        inline static int32_t ID() {
            return 1046;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        GroundSpeedReading() = default;
        GroundSpeedReading(const GroundSpeedReading&) = default;
        GroundSpeedReading& operator=(const GroundSpeedReading&) = default;
        GroundSpeedReading(GroundSpeedReading&&) = default;
        GroundSpeedReading& operator=(GroundSpeedReading&&) = default;
        ~GroundSpeedReading() = default;

    public:
        inline GroundSpeedReading& groundSpeed(const float &v) noexcept {
            m_groundSpeed = v;
            return *this;
        }
        inline float groundSpeed() const noexcept {
            return m_groundSpeed;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("groundSpeed"s), m_groundSpeed, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("groundSpeed"s), m_groundSpeed, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("groundSpeed"s), m_groundSpeed, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_groundSpeed{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::GroundSpeedReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::GroundSpeedReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_AXLEANGULARVELOCITYREADING_HPP
#define OPENDLV_PROXY_AXLEANGULARVELOCITYREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API AxleAngularVelocityReading {
    private:
        static constexpr const char* TheShortName = "AxleAngularVelocityReading";
        static constexpr const char* TheLongName = "opendlv.proxy.AxleAngularVelocityReading";

    public:
        inline static int32_t ID() {
            return 1047;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        AxleAngularVelocityReading() = default;
        AxleAngularVelocityReading(const AxleAngularVelocityReading&) = default;
        AxleAngularVelocityReading& operator=(const AxleAngularVelocityReading&) = default;
        AxleAngularVelocityReading(AxleAngularVelocityReading&&) = default;
        AxleAngularVelocityReading& operator=(AxleAngularVelocityReading&&) = default;
        ~AxleAngularVelocityReading() = default;

    public:
        inline AxleAngularVelocityReading& axleAngularVelocity(const float &v) noexcept {
            m_axleAngularVelocity = v;
            return *this;
        }
        inline float axleAngularVelocity() const noexcept {
            return m_axleAngularVelocity;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("axleAngularVelocity"s), m_axleAngularVelocity, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("axleAngularVelocity"s), m_axleAngularVelocity, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("axleAngularVelocity"s), m_axleAngularVelocity, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_axleAngularVelocity{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::AxleAngularVelocityReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::AxleAngularVelocityReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_STROKELENGTHREADING_HPP
#define OPENDLV_PROXY_STROKELENGTHREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API StrokeLengthReading {
    private:
        static constexpr const char* TheShortName = "StrokeLengthReading";
        static constexpr const char* TheLongName = "opendlv.proxy.StrokeLengthReading";

    public:
        inline static int32_t ID() {
            return 1048;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        StrokeLengthReading() = default;
        StrokeLengthReading(const StrokeLengthReading&) = default;
        StrokeLengthReading& operator=(const StrokeLengthReading&) = default;
        StrokeLengthReading(StrokeLengthReading&&) = default;
        StrokeLengthReading& operator=(StrokeLengthReading&&) = default;
        ~StrokeLengthReading() = default;

    public:
        inline StrokeLengthReading& strokeLength(const float &v) noexcept {
            m_strokeLength = v;
            return *this;
        }
        inline float strokeLength() const noexcept {
            return m_strokeLength;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("strokeLength"s), m_strokeLength, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("strokeLength"s), m_strokeLength, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("strokeLength"s), m_strokeLength, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_strokeLength{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::StrokeLengthReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::StrokeLengthReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_WEIGHTREADING_HPP
#define OPENDLV_PROXY_WEIGHTREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API WeightReading {
    private:
        static constexpr const char* TheShortName = "WeightReading";
        static constexpr const char* TheLongName = "opendlv.proxy.WeightReading";

    public:
        inline static int32_t ID() {
            return 1050;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        WeightReading() = default;
        WeightReading(const WeightReading&) = default;
        WeightReading& operator=(const WeightReading&) = default;
        WeightReading(WeightReading&&) = default;
        WeightReading& operator=(WeightReading&&) = default;
        ~WeightReading() = default;

    public:
        inline WeightReading& weight(const float &v) noexcept {
            m_weight = v;
            return *this;
        }
        inline float weight() const noexcept {
            return m_weight;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("weight"s), m_weight, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("weight"s), m_weight, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("weight"s), m_weight, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_weight{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::WeightReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::WeightReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_GEODETICWGS84HEADINGREADING_HPP
#define OPENDLV_PROXY_GEODETICWGS84HEADINGREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API GeodeticWgs84HeadingReading {
    private:
        static constexpr const char* TheShortName = "GeodeticWgs84HeadingReading";
        static constexpr const char* TheLongName = "opendlv.proxy.GeodeticWgs84HeadingReading";

    public:
        inline static int32_t ID() {
            return 1051;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        GeodeticWgs84HeadingReading() = default;
        GeodeticWgs84HeadingReading(const GeodeticWgs84HeadingReading&) = default;
        GeodeticWgs84HeadingReading& operator=(const GeodeticWgs84HeadingReading&) = default;
        GeodeticWgs84HeadingReading(GeodeticWgs84HeadingReading&&) = default;
        GeodeticWgs84HeadingReading& operator=(GeodeticWgs84HeadingReading&&) = default;
        ~GeodeticWgs84HeadingReading() = default;

    public:
        inline GeodeticWgs84HeadingReading& northHeading(const float &v) noexcept {
            m_northHeading = v;
            return *this;
        }
        inline float northHeading() const noexcept {
            return m_northHeading;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("northHeading"s), m_northHeading, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("northHeading"s), m_northHeading, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("northHeading"s), m_northHeading, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_northHeading{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::GeodeticWgs84HeadingReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::GeodeticWgs84HeadingReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_GEODETICWGS84POSITIONREADING_HPP
#define OPENDLV_PROXY_GEODETICWGS84POSITIONREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API GeodeticWgs84PositionReading {
    private:
        static constexpr const char* TheShortName = "GeodeticWgs84PositionReading";
        static constexpr const char* TheLongName = "opendlv.proxy.GeodeticWgs84PositionReading";

    public:
        inline static int32_t ID() {
            return 19;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        GeodeticWgs84PositionReading() = default;
        GeodeticWgs84PositionReading(const GeodeticWgs84PositionReading&) = default;
        GeodeticWgs84PositionReading& operator=(const GeodeticWgs84PositionReading&) = default;
        GeodeticWgs84PositionReading(GeodeticWgs84PositionReading&&) = default;
        GeodeticWgs84PositionReading& operator=(GeodeticWgs84PositionReading&&) = default;
        ~GeodeticWgs84PositionReading() = default;

    public:
        inline GeodeticWgs84PositionReading& latitude(const double &v) noexcept {
            m_latitude = v;
            return *this;
        }
        inline double latitude() const noexcept {
            return m_latitude;
        }
        inline GeodeticWgs84PositionReading& longitude(const double &v) noexcept {
            m_longitude = v;
            return *this;
        }
        inline double longitude() const noexcept {
            return m_longitude;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("double"s), std::move("latitude"s), m_latitude, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("double"s), std::move("longitude"s), m_longitude, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("double"s), std::move("latitude"s), m_latitude, visitor);
            doVisit(3, std::move("double"s), std::move("longitude"s), m_longitude, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("double"s), std::move("latitude"s), m_latitude, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("double"s), std::move("longitude"s), m_longitude, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        double m_latitude{ 0.0 }; // field identifier = 1.
        double m_longitude{ 0.0 }; // field identifier = 3.
};
}}

template<>
struct isVisitable<opendlv::proxy::GeodeticWgs84PositionReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::GeodeticWgs84PositionReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_IMAGEREADINGSHM_HPP
#define OPENDLV_PROXY_IMAGEREADINGSHM_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API ImageReadingShm {
    private:
        static constexpr const char* TheShortName = "ImageReadingShm";
        static constexpr const char* TheLongName = "opendlv.proxy.ImageReadingShm";

    public:
        inline static int32_t ID() {
            return 1054;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        ImageReadingShm() = default;
        ImageReadingShm(const ImageReadingShm&) = default;
        ImageReadingShm& operator=(const ImageReadingShm&) = default;
        ImageReadingShm(ImageReadingShm&&) = default;
        ImageReadingShm& operator=(ImageReadingShm&&) = default;
        ~ImageReadingShm() = default;

    public:
        inline ImageReadingShm& format(const std::string &v) noexcept {
            m_format = v;
            return *this;
        }
        inline std::string format() const noexcept {
            return m_format;
        }
        inline ImageReadingShm& width(const uint32_t &v) noexcept {
            m_width = v;
            return *this;
        }
        inline uint32_t width() const noexcept {
            return m_width;
        }
        inline ImageReadingShm& height(const uint32_t &v) noexcept {
            m_height = v;
            return *this;
        }
        inline uint32_t height() const noexcept {
            return m_height;
        }
        inline ImageReadingShm& location(const std::string &v) noexcept {
            m_location = v;
            return *this;
        }
        inline std::string location() const noexcept {
            return m_location;
        }
        inline ImageReadingShm& sampleId(const uint32_t &v) noexcept {
            m_sampleId = v;
            return *this;
        }
        inline uint32_t sampleId() const noexcept {
            return m_sampleId;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("std::string"s), std::move("format"s), m_format, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("uint32_t"s), std::move("width"s), m_width, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("uint32_t"s), std::move("height"s), m_height, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("std::string"s), std::move("location"s), m_location, visitor);
                return;
            }
            if (5 == fieldId) {
                doVisit(5, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("std::string"s), std::move("format"s), m_format, visitor);
            doVisit(2, std::move("uint32_t"s), std::move("width"s), m_width, visitor);
            doVisit(3, std::move("uint32_t"s), std::move("height"s), m_height, visitor);
            doVisit(4, std::move("std::string"s), std::move("location"s), m_location, visitor);
            doVisit(5, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("std::string"s), std::move("format"s), m_format, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("uint32_t"s), std::move("width"s), m_width, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("uint32_t"s), std::move("height"s), m_height, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("std::string"s), std::move("location"s), m_location, preVisit, visit, postVisit);
            doTripletForwardVisit(5, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        std::string m_format{ ""s }; // field identifier = 1.
        uint32_t m_width{ 0 }; // field identifier = 2.
        uint32_t m_height{ 0 }; // field identifier = 3.
        std::string m_location{ ""s }; // field identifier = 4.
        uint32_t m_sampleId{ 0 }; // field identifier = 5.
};
}}

template<>
struct isVisitable<opendlv::proxy::ImageReadingShm> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::ImageReadingShm> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_IMAGEREADING_HPP
#define OPENDLV_PROXY_IMAGEREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API ImageReading {
    private:
        static constexpr const char* TheShortName = "ImageReading";
        static constexpr const char* TheLongName = "opendlv.proxy.ImageReading";

    public:
        inline static int32_t ID() {
            return 1055;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        ImageReading() = default;
        ImageReading(const ImageReading&) = default;
        ImageReading& operator=(const ImageReading&) = default;
        ImageReading(ImageReading&&) = default;
        ImageReading& operator=(ImageReading&&) = default;
        ~ImageReading() = default;

    public:
        inline ImageReading& format(const std::string &v) noexcept {
            m_format = v;
            return *this;
        }
        inline std::string format() const noexcept {
            return m_format;
        }
        inline ImageReading& width(const uint32_t &v) noexcept {
            m_width = v;
            return *this;
        }
        inline uint32_t width() const noexcept {
            return m_width;
        }
        inline ImageReading& height(const uint32_t &v) noexcept {
            m_height = v;
            return *this;
        }
        inline uint32_t height() const noexcept {
            return m_height;
        }
        inline ImageReading& data(const std::string &v) noexcept {
            m_data = v;
            return *this;
        }
        inline std::string data() const noexcept {
            return m_data;
        }
        inline ImageReading& sampleId(const uint32_t &v) noexcept {
            m_sampleId = v;
            return *this;
        }
        inline uint32_t sampleId() const noexcept {
            return m_sampleId;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("std::string"s), std::move("format"s), m_format, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("uint32_t"s), std::move("width"s), m_width, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("uint32_t"s), std::move("height"s), m_height, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("std::string"s), std::move("data"s), m_data, visitor);
                return;
            }
            if (5 == fieldId) {
                doVisit(5, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("std::string"s), std::move("format"s), m_format, visitor);
            doVisit(2, std::move("uint32_t"s), std::move("width"s), m_width, visitor);
            doVisit(3, std::move("uint32_t"s), std::move("height"s), m_height, visitor);
            doVisit(4, std::move("std::string"s), std::move("data"s), m_data, visitor);
            doVisit(5, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("std::string"s), std::move("format"s), m_format, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("uint32_t"s), std::move("width"s), m_width, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("uint32_t"s), std::move("height"s), m_height, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("std::string"s), std::move("data"s), m_data, preVisit, visit, postVisit);
            doTripletForwardVisit(5, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        std::string m_format{ ""s }; // field identifier = 1.
        uint32_t m_width{ 0 }; // field identifier = 2.
        uint32_t m_height{ 0 }; // field identifier = 3.
        std::string m_data{ ""s }; // field identifier = 4.
        uint32_t m_sampleId{ 0 }; // field identifier = 5.
};
}}

template<>
struct isVisitable<opendlv::proxy::ImageReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::ImageReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_REMOTEMESSAGEREADING_HPP
#define OPENDLV_PROXY_REMOTEMESSAGEREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API RemoteMessageReading {
    private:
        static constexpr const char* TheShortName = "RemoteMessageReading";
        static constexpr const char* TheLongName = "opendlv.proxy.RemoteMessageReading";

    public:
        inline static int32_t ID() {
            return 1056;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        RemoteMessageReading() = default;
        RemoteMessageReading(const RemoteMessageReading&) = default;
        RemoteMessageReading& operator=(const RemoteMessageReading&) = default;
        RemoteMessageReading(RemoteMessageReading&&) = default;
        RemoteMessageReading& operator=(RemoteMessageReading&&) = default;
        ~RemoteMessageReading() = default;

    public:
        inline RemoteMessageReading& address(const std::string &v) noexcept {
            m_address = v;
            return *this;
        }
        inline std::string address() const noexcept {
            return m_address;
        }
        inline RemoteMessageReading& message(const std::string &v) noexcept {
            m_message = v;
            return *this;
        }
        inline std::string message() const noexcept {
            return m_message;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("std::string"s), std::move("address"s), m_address, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("std::string"s), std::move("message"s), m_message, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("std::string"s), std::move("address"s), m_address, visitor);
            doVisit(2, std::move("std::string"s), std::move("message"s), m_message, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("std::string"s), std::move("address"s), m_address, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("std::string"s), std::move("message"s), m_message, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        std::string m_address{ ""s }; // field identifier = 1.
        std::string m_message{ ""s }; // field identifier = 2.
};
}}

template<>
struct isVisitable<opendlv::proxy::RemoteMessageReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::RemoteMessageReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_POINTCLOUDANGULARLAYEREDREADINGSHM_HPP
#define OPENDLV_PROXY_POINTCLOUDANGULARLAYEREDREADINGSHM_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API PointCloudAngularLayeredReadingShm {
    private:
        static constexpr const char* TheShortName = "PointCloudAngularLayeredReadingShm";
        static constexpr const char* TheLongName = "opendlv.proxy.PointCloudAngularLayeredReadingShm";

    public:
        inline static int32_t ID() {
            return 1060;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        PointCloudAngularLayeredReadingShm() = default;
        PointCloudAngularLayeredReadingShm(const PointCloudAngularLayeredReadingShm&) = default;
        PointCloudAngularLayeredReadingShm& operator=(const PointCloudAngularLayeredReadingShm&) = default;
        PointCloudAngularLayeredReadingShm(PointCloudAngularLayeredReadingShm&&) = default;
        PointCloudAngularLayeredReadingShm& operator=(PointCloudAngularLayeredReadingShm&&) = default;
        ~PointCloudAngularLayeredReadingShm() = default;

    public:
        inline PointCloudAngularLayeredReadingShm& layerAngle(const float &v) noexcept {
            m_layerAngle = v;
            return *this;
        }
        inline float layerAngle() const noexcept {
            return m_layerAngle;
        }
        inline PointCloudAngularLayeredReadingShm& format(const std::string &v) noexcept {
            m_format = v;
            return *this;
        }
        inline std::string format() const noexcept {
            return m_format;
        }
        inline PointCloudAngularLayeredReadingShm& count(const uint32_t &v) noexcept {
            m_count = v;
            return *this;
        }
        inline uint32_t count() const noexcept {
            return m_count;
        }
        inline PointCloudAngularLayeredReadingShm& location(const std::string &v) noexcept {
            m_location = v;
            return *this;
        }
        inline std::string location() const noexcept {
            return m_location;
        }
        inline PointCloudAngularLayeredReadingShm& sampleId(const uint32_t &v) noexcept {
            m_sampleId = v;
            return *this;
        }
        inline uint32_t sampleId() const noexcept {
            return m_sampleId;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("layerAngle"s), m_layerAngle, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("std::string"s), std::move("format"s), m_format, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("uint32_t"s), std::move("count"s), m_count, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("std::string"s), std::move("location"s), m_location, visitor);
                return;
            }
            if (5 == fieldId) {
                doVisit(5, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("layerAngle"s), m_layerAngle, visitor);
            doVisit(2, std::move("std::string"s), std::move("format"s), m_format, visitor);
            doVisit(3, std::move("uint32_t"s), std::move("count"s), m_count, visitor);
            doVisit(4, std::move("std::string"s), std::move("location"s), m_location, visitor);
            doVisit(5, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("layerAngle"s), m_layerAngle, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("std::string"s), std::move("format"s), m_format, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("uint32_t"s), std::move("count"s), m_count, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("std::string"s), std::move("location"s), m_location, preVisit, visit, postVisit);
            doTripletForwardVisit(5, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_layerAngle{ 0.0f }; // field identifier = 1.
        std::string m_format{ ""s }; // field identifier = 2.
        uint32_t m_count{ 0 }; // field identifier = 3.
        std::string m_location{ ""s }; // field identifier = 4.
        uint32_t m_sampleId{ 0 }; // field identifier = 5.
};
}}

template<>
struct isVisitable<opendlv::proxy::PointCloudAngularLayeredReadingShm> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::PointCloudAngularLayeredReadingShm> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_POINTCLOUDANGULARLAYEREDREADING_HPP
#define OPENDLV_PROXY_POINTCLOUDANGULARLAYEREDREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API PointCloudAngularLayeredReading {
    private:
        static constexpr const char* TheShortName = "PointCloudAngularLayeredReading";
        static constexpr const char* TheLongName = "opendlv.proxy.PointCloudAngularLayeredReading";

    public:
        inline static int32_t ID() {
            return 1061;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        PointCloudAngularLayeredReading() = default;
        PointCloudAngularLayeredReading(const PointCloudAngularLayeredReading&) = default;
        PointCloudAngularLayeredReading& operator=(const PointCloudAngularLayeredReading&) = default;
        PointCloudAngularLayeredReading(PointCloudAngularLayeredReading&&) = default;
        PointCloudAngularLayeredReading& operator=(PointCloudAngularLayeredReading&&) = default;
        ~PointCloudAngularLayeredReading() = default;

    public:
        inline PointCloudAngularLayeredReading& layerAngle(const float &v) noexcept {
            m_layerAngle = v;
            return *this;
        }
        inline float layerAngle() const noexcept {
            return m_layerAngle;
        }
        inline PointCloudAngularLayeredReading& format(const std::string &v) noexcept {
            m_format = v;
            return *this;
        }
        inline std::string format() const noexcept {
            return m_format;
        }
        inline PointCloudAngularLayeredReading& count(const uint32_t &v) noexcept {
            m_count = v;
            return *this;
        }
        inline uint32_t count() const noexcept {
            return m_count;
        }
        inline PointCloudAngularLayeredReading& data(const std::string &v) noexcept {
            m_data = v;
            return *this;
        }
        inline std::string data() const noexcept {
            return m_data;
        }
        inline PointCloudAngularLayeredReading& sampleId(const uint32_t &v) noexcept {
            m_sampleId = v;
            return *this;
        }
        inline uint32_t sampleId() const noexcept {
            return m_sampleId;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("layerAngle"s), m_layerAngle, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("std::string"s), std::move("format"s), m_format, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("uint32_t"s), std::move("count"s), m_count, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("std::string"s), std::move("data"s), m_data, visitor);
                return;
            }
            if (5 == fieldId) {
                doVisit(5, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("layerAngle"s), m_layerAngle, visitor);
            doVisit(2, std::move("std::string"s), std::move("format"s), m_format, visitor);
            doVisit(3, std::move("uint32_t"s), std::move("count"s), m_count, visitor);
            doVisit(4, std::move("std::string"s), std::move("data"s), m_data, visitor);
            doVisit(5, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("layerAngle"s), m_layerAngle, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("std::string"s), std::move("format"s), m_format, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("uint32_t"s), std::move("count"s), m_count, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("std::string"s), std::move("data"s), m_data, preVisit, visit, postVisit);
            doTripletForwardVisit(5, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_layerAngle{ 0.0f }; // field identifier = 1.
        std::string m_format{ ""s }; // field identifier = 2.
        uint32_t m_count{ 0 }; // field identifier = 3.
        std::string m_data{ ""s }; // field identifier = 4.
        uint32_t m_sampleId{ 0 }; // field identifier = 5.
};
}}

template<>
struct isVisitable<opendlv::proxy::PointCloudAngularLayeredReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::PointCloudAngularLayeredReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_STEPREQUEST_HPP
#define OPENDLV_PROXY_STEPREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API StepRequest {
    private:
        static constexpr const char* TheShortName = "StepRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.StepRequest";

    public:
        inline static int32_t ID() {
            return 1079;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        StepRequest() = default;
        StepRequest(const StepRequest&) = default;
        StepRequest& operator=(const StepRequest&) = default;
        StepRequest(StepRequest&&) = default;
        StepRequest& operator=(StepRequest&&) = default;
        ~StepRequest() = default;

    public:
        inline StepRequest& steps(const int32_t &v) noexcept {
            m_steps = v;
            return *this;
        }
        inline int32_t steps() const noexcept {
            return m_steps;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("int32_t"s), std::move("steps"s), m_steps, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("int32_t"s), std::move("steps"s), m_steps, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("int32_t"s), std::move("steps"s), m_steps, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        int32_t m_steps{ 0 }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::StepRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::StepRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_PRESSUREREQUEST_HPP
#define OPENDLV_PROXY_PRESSUREREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API PressureRequest {
    private:
        static constexpr const char* TheShortName = "PressureRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.PressureRequest";

    public:
        inline static int32_t ID() {
            return 1080;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        PressureRequest() = default;
        PressureRequest(const PressureRequest&) = default;
        PressureRequest& operator=(const PressureRequest&) = default;
        PressureRequest(PressureRequest&&) = default;
        PressureRequest& operator=(PressureRequest&&) = default;
        ~PressureRequest() = default;

    public:
        inline PressureRequest& pressure(const float &v) noexcept {
            m_pressure = v;
            return *this;
        }
        inline float pressure() const noexcept {
            return m_pressure;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("pressure"s), m_pressure, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("pressure"s), m_pressure, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("pressure"s), m_pressure, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_pressure{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::PressureRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::PressureRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_TEMPERATUREREQUEST_HPP
#define OPENDLV_PROXY_TEMPERATUREREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API TemperatureRequest {
    private:
        static constexpr const char* TheShortName = "TemperatureRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.TemperatureRequest";

    public:
        inline static int32_t ID() {
            return 1081;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        TemperatureRequest() = default;
        TemperatureRequest(const TemperatureRequest&) = default;
        TemperatureRequest& operator=(const TemperatureRequest&) = default;
        TemperatureRequest(TemperatureRequest&&) = default;
        TemperatureRequest& operator=(TemperatureRequest&&) = default;
        ~TemperatureRequest() = default;

    public:
        inline TemperatureRequest& temperature(const float &v) noexcept {
            m_temperature = v;
            return *this;
        }
        inline float temperature() const noexcept {
            return m_temperature;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("temperature"s), m_temperature, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("temperature"s), m_temperature, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("temperature"s), m_temperature, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_temperature{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::TemperatureRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::TemperatureRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_TORQUEREQUEST_HPP
#define OPENDLV_PROXY_TORQUEREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API TorqueRequest {
    private:
        static constexpr const char* TheShortName = "TorqueRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.TorqueRequest";

    public:
        inline static int32_t ID() {
            return 1082;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        TorqueRequest() = default;
        TorqueRequest(const TorqueRequest&) = default;
        TorqueRequest& operator=(const TorqueRequest&) = default;
        TorqueRequest(TorqueRequest&&) = default;
        TorqueRequest& operator=(TorqueRequest&&) = default;
        ~TorqueRequest() = default;

    public:
        inline TorqueRequest& torque(const float &v) noexcept {
            m_torque = v;
            return *this;
        }
        inline float torque() const noexcept {
            return m_torque;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("torque"s), m_torque, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("torque"s), m_torque, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("torque"s), m_torque, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_torque{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::TorqueRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::TorqueRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_VOLTAGEREQUEST_HPP
#define OPENDLV_PROXY_VOLTAGEREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API VoltageRequest {
    private:
        static constexpr const char* TheShortName = "VoltageRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.VoltageRequest";

    public:
        inline static int32_t ID() {
            return 1083;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        VoltageRequest() = default;
        VoltageRequest(const VoltageRequest&) = default;
        VoltageRequest& operator=(const VoltageRequest&) = default;
        VoltageRequest(VoltageRequest&&) = default;
        VoltageRequest& operator=(VoltageRequest&&) = default;
        ~VoltageRequest() = default;

    public:
        inline VoltageRequest& voltage(const float &v) noexcept {
            m_voltage = v;
            return *this;
        }
        inline float voltage() const noexcept {
            return m_voltage;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("voltage"s), m_voltage, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("voltage"s), m_voltage, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("voltage"s), m_voltage, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_voltage{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::VoltageRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::VoltageRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_ANGLEREQUEST_HPP
#define OPENDLV_PROXY_ANGLEREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API AngleRequest {
    private:
        static constexpr const char* TheShortName = "AngleRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.AngleRequest";

    public:
        inline static int32_t ID() {
            return 1084;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        AngleRequest() = default;
        AngleRequest(const AngleRequest&) = default;
        AngleRequest& operator=(const AngleRequest&) = default;
        AngleRequest(AngleRequest&&) = default;
        AngleRequest& operator=(AngleRequest&&) = default;
        ~AngleRequest() = default;

    public:
        inline AngleRequest& angle(const float &v) noexcept {
            m_angle = v;
            return *this;
        }
        inline float angle() const noexcept {
            return m_angle;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("angle"s), m_angle, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("angle"s), m_angle, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("angle"s), m_angle, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_angle{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::AngleRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::AngleRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_SWITCHSTATEREQUEST_HPP
#define OPENDLV_PROXY_SWITCHSTATEREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API SwitchStateRequest {
    private:
        static constexpr const char* TheShortName = "SwitchStateRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.SwitchStateRequest";

    public:
        inline static int32_t ID() {
            return 1085;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        SwitchStateRequest() = default;
        SwitchStateRequest(const SwitchStateRequest&) = default;
        SwitchStateRequest& operator=(const SwitchStateRequest&) = default;
        SwitchStateRequest(SwitchStateRequest&&) = default;
        SwitchStateRequest& operator=(SwitchStateRequest&&) = default;
        ~SwitchStateRequest() = default;

    public:
        inline SwitchStateRequest& state(const int16_t &v) noexcept {
            m_state = v;
            return *this;
        }
        inline int16_t state() const noexcept {
            return m_state;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("int16_t"s), std::move("state"s), m_state, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("int16_t"s), std::move("state"s), m_state, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("int16_t"s), std::move("state"s), m_state, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        int16_t m_state{ 0 }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::SwitchStateRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::SwitchStateRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_PEDALPOSITIONREQUEST_HPP
#define OPENDLV_PROXY_PEDALPOSITIONREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API PedalPositionRequest {
    private:
        static constexpr const char* TheShortName = "PedalPositionRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.PedalPositionRequest";

    public:
        inline static int32_t ID() {
            return 1086;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        PedalPositionRequest() = default;
        PedalPositionRequest(const PedalPositionRequest&) = default;
        PedalPositionRequest& operator=(const PedalPositionRequest&) = default;
        PedalPositionRequest(PedalPositionRequest&&) = default;
        PedalPositionRequest& operator=(PedalPositionRequest&&) = default;
        ~PedalPositionRequest() = default;

    public:
        inline PedalPositionRequest& position(const float &v) noexcept {
            m_position = v;
            return *this;
        }
        inline float position() const noexcept {
            return m_position;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("position"s), m_position, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("position"s), m_position, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("position"s), m_position, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_position{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::PedalPositionRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::PedalPositionRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_PULSEWIDTHMODULATIONREQUEST_HPP
#define OPENDLV_PROXY_PULSEWIDTHMODULATIONREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API PulseWidthModulationRequest {
    private:
        static constexpr const char* TheShortName = "PulseWidthModulationRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.PulseWidthModulationRequest";

    public:
        inline static int32_t ID() {
            return 1087;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        PulseWidthModulationRequest() = default;
        PulseWidthModulationRequest(const PulseWidthModulationRequest&) = default;
        PulseWidthModulationRequest& operator=(const PulseWidthModulationRequest&) = default;
        PulseWidthModulationRequest(PulseWidthModulationRequest&&) = default;
        PulseWidthModulationRequest& operator=(PulseWidthModulationRequest&&) = default;
        ~PulseWidthModulationRequest() = default;

    public:
        inline PulseWidthModulationRequest& dutyCycleNs(const uint32_t &v) noexcept {
            m_dutyCycleNs = v;
            return *this;
        }
        inline uint32_t dutyCycleNs() const noexcept {
            return m_dutyCycleNs;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("uint32_t"s), std::move("dutyCycleNs"s), m_dutyCycleNs, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("uint32_t"s), std::move("dutyCycleNs"s), m_dutyCycleNs, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("uint32_t"s), std::move("dutyCycleNs"s), m_dutyCycleNs, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        uint32_t m_dutyCycleNs{ 0 }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::PulseWidthModulationRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::PulseWidthModulationRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_STROKELENGTHREQUEST_HPP
#define OPENDLV_PROXY_STROKELENGTHREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API StrokeLengthRequest {
    private:
        static constexpr const char* TheShortName = "StrokeLengthRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.StrokeLengthRequest";

    public:
        inline static int32_t ID() {
            return 1088;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        StrokeLengthRequest() = default;
        StrokeLengthRequest(const StrokeLengthRequest&) = default;
        StrokeLengthRequest& operator=(const StrokeLengthRequest&) = default;
        StrokeLengthRequest(StrokeLengthRequest&&) = default;
        StrokeLengthRequest& operator=(StrokeLengthRequest&&) = default;
        ~StrokeLengthRequest() = default;

    public:
        inline StrokeLengthRequest& strokeLength(const float &v) noexcept {
            m_strokeLength = v;
            return *this;
        }
        inline float strokeLength() const noexcept {
            return m_strokeLength;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("strokeLength"s), m_strokeLength, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("strokeLength"s), m_strokeLength, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("strokeLength"s), m_strokeLength, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_strokeLength{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::StrokeLengthRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::StrokeLengthRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_GROUNDMOTIONREQUEST_HPP
#define OPENDLV_PROXY_GROUNDMOTIONREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API GroundMotionRequest {
    private:
        static constexpr const char* TheShortName = "GroundMotionRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.GroundMotionRequest";

    public:
        inline static int32_t ID() {
            return 1089;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        GroundMotionRequest() = default;
        GroundMotionRequest(const GroundMotionRequest&) = default;
        GroundMotionRequest& operator=(const GroundMotionRequest&) = default;
        GroundMotionRequest(GroundMotionRequest&&) = default;
        GroundMotionRequest& operator=(GroundMotionRequest&&) = default;
        ~GroundMotionRequest() = default;

    public:
        inline GroundMotionRequest& vx(const float &v) noexcept {
            m_vx = v;
            return *this;
        }
        inline float vx() const noexcept {
            return m_vx;
        }
        inline GroundMotionRequest& vy(const float &v) noexcept {
            m_vy = v;
            return *this;
        }
        inline float vy() const noexcept {
            return m_vy;
        }
        inline GroundMotionRequest& vz(const float &v) noexcept {
            m_vz = v;
            return *this;
        }
        inline float vz() const noexcept {
            return m_vz;
        }
        inline GroundMotionRequest& rollRate(const float &v) noexcept {
            m_rollRate = v;
            return *this;
        }
        inline float rollRate() const noexcept {
            return m_rollRate;
        }
        inline GroundMotionRequest& pitchRate(const float &v) noexcept {
            m_pitchRate = v;
            return *this;
        }
        inline float pitchRate() const noexcept {
            return m_pitchRate;
        }
        inline GroundMotionRequest& yawRate(const float &v) noexcept {
            m_yawRate = v;
            return *this;
        }
        inline float yawRate() const noexcept {
            return m_yawRate;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("vx"s), m_vx, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("vy"s), m_vy, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("vz"s), m_vz, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("float"s), std::move("rollRate"s), m_rollRate, visitor);
                return;
            }
            if (5 == fieldId) {
                doVisit(5, std::move("float"s), std::move("pitchRate"s), m_pitchRate, visitor);
                return;
            }
            if (6 == fieldId) {
                doVisit(6, std::move("float"s), std::move("yawRate"s), m_yawRate, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("vx"s), m_vx, visitor);
            doVisit(2, std::move("float"s), std::move("vy"s), m_vy, visitor);
            doVisit(3, std::move("float"s), std::move("vz"s), m_vz, visitor);
            doVisit(4, std::move("float"s), std::move("rollRate"s), m_rollRate, visitor);
            doVisit(5, std::move("float"s), std::move("pitchRate"s), m_pitchRate, visitor);
            doVisit(6, std::move("float"s), std::move("yawRate"s), m_yawRate, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("vx"s), m_vx, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("vy"s), m_vy, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("vz"s), m_vz, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("float"s), std::move("rollRate"s), m_rollRate, preVisit, visit, postVisit);
            doTripletForwardVisit(5, std::move("float"s), std::move("pitchRate"s), m_pitchRate, preVisit, visit, postVisit);
            doTripletForwardVisit(6, std::move("float"s), std::move("yawRate"s), m_yawRate, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_vx{ 0.0f }; // field identifier = 1.
        float m_vy{ 0.0f }; // field identifier = 2.
        float m_vz{ 0.0f }; // field identifier = 3.
        float m_rollRate{ 0.0f }; // field identifier = 4.
        float m_pitchRate{ 0.0f }; // field identifier = 5.
        float m_yawRate{ 0.0f }; // field identifier = 6.
};
}}

template<>
struct isVisitable<opendlv::proxy::GroundMotionRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::GroundMotionRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_GROUNDSTEERINGREQUEST_HPP
#define OPENDLV_PROXY_GROUNDSTEERINGREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API GroundSteeringRequest {
    private:
        static constexpr const char* TheShortName = "GroundSteeringRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.GroundSteeringRequest";

    public:
        inline static int32_t ID() {
            return 1090;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        GroundSteeringRequest() = default;
        GroundSteeringRequest(const GroundSteeringRequest&) = default;
        GroundSteeringRequest& operator=(const GroundSteeringRequest&) = default;
        GroundSteeringRequest(GroundSteeringRequest&&) = default;
        GroundSteeringRequest& operator=(GroundSteeringRequest&&) = default;
        ~GroundSteeringRequest() = default;

    public:
        inline GroundSteeringRequest& groundSteering(const float &v) noexcept {
            m_groundSteering = v;
            return *this;
        }
        inline float groundSteering() const noexcept {
            return m_groundSteering;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("groundSteering"s), m_groundSteering, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("groundSteering"s), m_groundSteering, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("groundSteering"s), m_groundSteering, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_groundSteering{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::GroundSteeringRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::GroundSteeringRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_GROUNDSPEEDREQUEST_HPP
#define OPENDLV_PROXY_GROUNDSPEEDREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API GroundSpeedRequest {
    private:
        static constexpr const char* TheShortName = "GroundSpeedRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.GroundSpeedRequest";

    public:
        inline static int32_t ID() {
            return 1091;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        GroundSpeedRequest() = default;
        GroundSpeedRequest(const GroundSpeedRequest&) = default;
        GroundSpeedRequest& operator=(const GroundSpeedRequest&) = default;
        GroundSpeedRequest(GroundSpeedRequest&&) = default;
        GroundSpeedRequest& operator=(GroundSpeedRequest&&) = default;
        ~GroundSpeedRequest() = default;

    public:
        inline GroundSpeedRequest& groundSpeed(const float &v) noexcept {
            m_groundSpeed = v;
            return *this;
        }
        inline float groundSpeed() const noexcept {
            return m_groundSpeed;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("groundSpeed"s), m_groundSpeed, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("groundSpeed"s), m_groundSpeed, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("groundSpeed"s), m_groundSpeed, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_groundSpeed{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::GroundSpeedRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::GroundSpeedRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_GROUNDACCELERATIONREQUEST_HPP
#define OPENDLV_PROXY_GROUNDACCELERATIONREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API GroundAccelerationRequest {
    private:
        static constexpr const char* TheShortName = "GroundAccelerationRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.GroundAccelerationRequest";

    public:
        inline static int32_t ID() {
            return 1092;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        GroundAccelerationRequest() = default;
        GroundAccelerationRequest(const GroundAccelerationRequest&) = default;
        GroundAccelerationRequest& operator=(const GroundAccelerationRequest&) = default;
        GroundAccelerationRequest(GroundAccelerationRequest&&) = default;
        GroundAccelerationRequest& operator=(GroundAccelerationRequest&&) = default;
        ~GroundAccelerationRequest() = default;

    public:
        inline GroundAccelerationRequest& groundAcceleration(const float &v) noexcept {
            m_groundAcceleration = v;
            return *this;
        }
        inline float groundAcceleration() const noexcept {
            return m_groundAcceleration;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("groundAcceleration"s), m_groundAcceleration, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("groundAcceleration"s), m_groundAcceleration, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("groundAcceleration"s), m_groundAcceleration, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_groundAcceleration{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::GroundAccelerationRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::GroundAccelerationRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_GROUNDDECELERATIONREQUEST_HPP
#define OPENDLV_PROXY_GROUNDDECELERATIONREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API GroundDecelerationRequest {
    private:
        static constexpr const char* TheShortName = "GroundDecelerationRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.GroundDecelerationRequest";

    public:
        inline static int32_t ID() {
            return 1093;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        GroundDecelerationRequest() = default;
        GroundDecelerationRequest(const GroundDecelerationRequest&) = default;
        GroundDecelerationRequest& operator=(const GroundDecelerationRequest&) = default;
        GroundDecelerationRequest(GroundDecelerationRequest&&) = default;
        GroundDecelerationRequest& operator=(GroundDecelerationRequest&&) = default;
        ~GroundDecelerationRequest() = default;

    public:
        inline GroundDecelerationRequest& groundDeceleration(const float &v) noexcept {
            m_groundDeceleration = v;
            return *this;
        }
        inline float groundDeceleration() const noexcept {
            return m_groundDeceleration;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("groundDeceleration"s), m_groundDeceleration, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("groundDeceleration"s), m_groundDeceleration, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("groundDeceleration"s), m_groundDeceleration, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_groundDeceleration{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::GroundDecelerationRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::GroundDecelerationRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_AXLEANGULARVELOCITYREQUEST_HPP
#define OPENDLV_PROXY_AXLEANGULARVELOCITYREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API AxleAngularVelocityRequest {
    private:
        static constexpr const char* TheShortName = "AxleAngularVelocityRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.AxleAngularVelocityRequest";

    public:
        inline static int32_t ID() {
            return 1094;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        AxleAngularVelocityRequest() = default;
        AxleAngularVelocityRequest(const AxleAngularVelocityRequest&) = default;
        AxleAngularVelocityRequest& operator=(const AxleAngularVelocityRequest&) = default;
        AxleAngularVelocityRequest(AxleAngularVelocityRequest&&) = default;
        AxleAngularVelocityRequest& operator=(AxleAngularVelocityRequest&&) = default;
        ~AxleAngularVelocityRequest() = default;

    public:
        inline AxleAngularVelocityRequest& axleAngularVelocity(const float &v) noexcept {
            m_axleAngularVelocity = v;
            return *this;
        }
        inline float axleAngularVelocity() const noexcept {
            return m_axleAngularVelocity;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("axleAngularVelocity"s), m_axleAngularVelocity, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("axleAngularVelocity"s), m_axleAngularVelocity, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("axleAngularVelocity"s), m_axleAngularVelocity, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_axleAngularVelocity{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::AxleAngularVelocityRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::AxleAngularVelocityRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_REMOTEMESSAGEREQUEST_HPP
#define OPENDLV_PROXY_REMOTEMESSAGEREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API RemoteMessageRequest {
    private:
        static constexpr const char* TheShortName = "RemoteMessageRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.RemoteMessageRequest";

    public:
        inline static int32_t ID() {
            return 1095;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        RemoteMessageRequest() = default;
        RemoteMessageRequest(const RemoteMessageRequest&) = default;
        RemoteMessageRequest& operator=(const RemoteMessageRequest&) = default;
        RemoteMessageRequest(RemoteMessageRequest&&) = default;
        RemoteMessageRequest& operator=(RemoteMessageRequest&&) = default;
        ~RemoteMessageRequest() = default;

    public:
        inline RemoteMessageRequest& address(const std::string &v) noexcept {
            m_address = v;
            return *this;
        }
        inline std::string address() const noexcept {
            return m_address;
        }
        inline RemoteMessageRequest& message(const std::string &v) noexcept {
            m_message = v;
            return *this;
        }
        inline std::string message() const noexcept {
            return m_message;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("std::string"s), std::move("address"s), m_address, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("std::string"s), std::move("message"s), m_message, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("std::string"s), std::move("address"s), m_address, visitor);
            doVisit(2, std::move("std::string"s), std::move("message"s), m_message, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("std::string"s), std::move("address"s), m_address, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("std::string"s), std::move("message"s), m_message, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        std::string m_address{ ""s }; // field identifier = 1.
        std::string m_message{ ""s }; // field identifier = 2.
};
}}

template<>
struct isVisitable<opendlv::proxy::RemoteMessageRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::RemoteMessageRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_SYSTEM_SIGNALSTATUSMESSAGE_HPP
#define OPENDLV_SYSTEM_SIGNALSTATUSMESSAGE_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace system {
using namespace std::string_literals; // NOLINT
class LIB_API SignalStatusMessage {
    private:
        static constexpr const char* TheShortName = "SignalStatusMessage";
        static constexpr const char* TheLongName = "opendlv.system.SignalStatusMessage";

    public:
        inline static int32_t ID() {
            return 1100;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        SignalStatusMessage() = default;
        SignalStatusMessage(const SignalStatusMessage&) = default;
        SignalStatusMessage& operator=(const SignalStatusMessage&) = default;
        SignalStatusMessage(SignalStatusMessage&&) = default;
        SignalStatusMessage& operator=(SignalStatusMessage&&) = default;
        ~SignalStatusMessage() = default;

    public:
        inline SignalStatusMessage& code(const int32_t &v) noexcept {
            m_code = v;
            return *this;
        }
        inline int32_t code() const noexcept {
            return m_code;
        }
        inline SignalStatusMessage& description(const std::string &v) noexcept {
            m_description = v;
            return *this;
        }
        inline std::string description() const noexcept {
            return m_description;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("int32_t"s), std::move("code"s), m_code, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("std::string"s), std::move("description"s), m_description, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("int32_t"s), std::move("code"s), m_code, visitor);
            doVisit(2, std::move("std::string"s), std::move("description"s), m_description, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("int32_t"s), std::move("code"s), m_code, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("std::string"s), std::move("description"s), m_description, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        int32_t m_code{ 0 }; // field identifier = 1.
        std::string m_description{ ""s }; // field identifier = 2.
};
}}

template<>
struct isVisitable<opendlv::system::SignalStatusMessage> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::system::SignalStatusMessage> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_SYSTEM_SYSTEMSTATUSMESSAGE_HPP
#define OPENDLV_SYSTEM_SYSTEMSTATUSMESSAGE_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace system {
using namespace std::string_literals; // NOLINT
class LIB_API SystemStatusMessage {
    private:
        static constexpr const char* TheShortName = "SystemStatusMessage";
        static constexpr const char* TheLongName = "opendlv.system.SystemStatusMessage";

    public:
        inline static int32_t ID() {
            return 1101;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        SystemStatusMessage() = default;
        SystemStatusMessage(const SystemStatusMessage&) = default;
        SystemStatusMessage& operator=(const SystemStatusMessage&) = default;
        SystemStatusMessage(SystemStatusMessage&&) = default;
        SystemStatusMessage& operator=(SystemStatusMessage&&) = default;
        ~SystemStatusMessage() = default;

    public:
        inline SystemStatusMessage& code(const int32_t &v) noexcept {
            m_code = v;
            return *this;
        }
        inline int32_t code() const noexcept {
            return m_code;
        }
        inline SystemStatusMessage& description(const std::string &v) noexcept {
            m_description = v;
            return *this;
        }
        inline std::string description() const noexcept {
            return m_description;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("int32_t"s), std::move("code"s), m_code, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("std::string"s), std::move("description"s), m_description, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("int32_t"s), std::move("code"s), m_code, visitor);
            doVisit(2, std::move("std::string"s), std::move("description"s), m_description, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("int32_t"s), std::move("code"s), m_code, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("std::string"s), std::move("description"s), m_description, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        int32_t m_code{ 0 }; // field identifier = 1.
        std::string m_description{ ""s }; // field identifier = 2.
};
}}

template<>
struct isVisitable<opendlv::system::SystemStatusMessage> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::system::SystemStatusMessage> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_SYSTEM_NETWORKSTATUSMESSAGE_HPP
#define OPENDLV_SYSTEM_NETWORKSTATUSMESSAGE_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace system {
using namespace std::string_literals; // NOLINT
class LIB_API NetworkStatusMessage {
    private:
        static constexpr const char* TheShortName = "NetworkStatusMessage";
        static constexpr const char* TheLongName = "opendlv.system.NetworkStatusMessage";

    public:
        inline static int32_t ID() {
            return 1102;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        NetworkStatusMessage() = default;
        NetworkStatusMessage(const NetworkStatusMessage&) = default;
        NetworkStatusMessage& operator=(const NetworkStatusMessage&) = default;
        NetworkStatusMessage(NetworkStatusMessage&&) = default;
        NetworkStatusMessage& operator=(NetworkStatusMessage&&) = default;
        ~NetworkStatusMessage() = default;

    public:
        inline NetworkStatusMessage& code(const int32_t &v) noexcept {
            m_code = v;
            return *this;
        }
        inline int32_t code() const noexcept {
            return m_code;
        }
        inline NetworkStatusMessage& description(const std::string &v) noexcept {
            m_description = v;
            return *this;
        }
        inline std::string description() const noexcept {
            return m_description;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("int32_t"s), std::move("code"s), m_code, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("std::string"s), std::move("description"s), m_description, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("int32_t"s), std::move("code"s), m_code, visitor);
            doVisit(2, std::move("std::string"s), std::move("description"s), m_description, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("int32_t"s), std::move("code"s), m_code, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("std::string"s), std::move("description"s), m_description, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        int32_t m_code{ 0 }; // field identifier = 1.
        std::string m_description{ ""s }; // field identifier = 2.
};
}}

template<>
struct isVisitable<opendlv::system::NetworkStatusMessage> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::system::NetworkStatusMessage> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_SYSTEM_LOGMESSAGE_HPP
#define OPENDLV_SYSTEM_LOGMESSAGE_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace system {
using namespace std::string_literals; // NOLINT
class LIB_API LogMessage {
    private:
        static constexpr const char* TheShortName = "LogMessage";
        static constexpr const char* TheLongName = "opendlv.system.LogMessage";

    public:
        inline static int32_t ID() {
            return 1103;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        LogMessage() = default;
        LogMessage(const LogMessage&) = default;
        LogMessage& operator=(const LogMessage&) = default;
        LogMessage(LogMessage&&) = default;
        LogMessage& operator=(LogMessage&&) = default;
        ~LogMessage() = default;

    public:
        inline LogMessage& level(const uint8_t &v) noexcept {
            m_level = v;
            return *this;
        }
        inline uint8_t level() const noexcept {
            return m_level;
        }
        inline LogMessage& description(const std::string &v) noexcept {
            m_description = v;
            return *this;
        }
        inline std::string description() const noexcept {
            return m_description;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("uint8_t"s), std::move("level"s), m_level, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("std::string"s), std::move("description"s), m_description, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("uint8_t"s), std::move("level"s), m_level, visitor);
            doVisit(2, std::move("std::string"s), std::move("description"s), m_description, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("uint8_t"s), std::move("level"s), m_level, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("std::string"s), std::move("description"s), m_description, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        uint8_t m_level{ 6 }; // field identifier = 1.
        std::string m_description{ ""s }; // field identifier = 2.
};
}}

template<>
struct isVisitable<opendlv::system::LogMessage> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::system::LogMessage> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_SYSTEM_COMMAND_HPP
#define OPENDLV_SYSTEM_COMMAND_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace system {
using namespace std::string_literals; // NOLINT
class LIB_API Command {
    private:
        static constexpr const char* TheShortName = "Command";
        static constexpr const char* TheLongName = "opendlv.system.Command";

    public:
        inline static int32_t ID() {
            return 1104;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        Command() = default;
        Command(const Command&) = default;
        Command& operator=(const Command&) = default;
        Command(Command&&) = default;
        Command& operator=(Command&&) = default;
        ~Command() = default;

    public:
        inline Command& command(const std::string &v) noexcept {
            m_command = v;
            return *this;
        }
        inline std::string command() const noexcept {
            return m_command;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("std::string"s), std::move("command"s), m_command, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("std::string"s), std::move("command"s), m_command, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("std::string"s), std::move("command"s), m_command, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        std::string m_command{ ""s }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::system::Command> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::system::Command> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_SENSATION_DIRECTION_HPP
#define OPENDLV_LOGIC_SENSATION_DIRECTION_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace sensation {
using namespace std::string_literals; // NOLINT
class LIB_API Direction {
    private:
        static constexpr const char* TheShortName = "Direction";
        static constexpr const char* TheLongName = "opendlv.logic.sensation.Direction";

    public:
        inline static int32_t ID() {
            return 1110;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        Direction() = default;
        Direction(const Direction&) = default;
        Direction& operator=(const Direction&) = default;
        Direction(Direction&&) = default;
        Direction& operator=(Direction&&) = default;
        ~Direction() = default;

    public:
        inline Direction& azimuthAngle(const float &v) noexcept {
            m_azimuthAngle = v;
            return *this;
        }
        inline float azimuthAngle() const noexcept {
            return m_azimuthAngle;
        }
        inline Direction& zenithAngle(const float &v) noexcept {
            m_zenithAngle = v;
            return *this;
        }
        inline float zenithAngle() const noexcept {
            return m_zenithAngle;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, visitor);
            doVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_azimuthAngle{ 0.0f }; // field identifier = 1.
        float m_zenithAngle{ 0.0f }; // field identifier = 2.
};
}}}

template<>
struct isVisitable<opendlv::logic::sensation::Direction> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::sensation::Direction> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_SENSATION_POINT_HPP
#define OPENDLV_LOGIC_SENSATION_POINT_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace sensation {
using namespace std::string_literals; // NOLINT
class LIB_API Point {
    private:
        static constexpr const char* TheShortName = "Point";
        static constexpr const char* TheLongName = "opendlv.logic.sensation.Point";

    public:
        inline static int32_t ID() {
            return 1111;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        Point() = default;
        Point(const Point&) = default;
        Point& operator=(const Point&) = default;
        Point(Point&&) = default;
        Point& operator=(Point&&) = default;
        ~Point() = default;

    public:
        inline Point& azimuthAngle(const float &v) noexcept {
            m_azimuthAngle = v;
            return *this;
        }
        inline float azimuthAngle() const noexcept {
            return m_azimuthAngle;
        }
        inline Point& zenithAngle(const float &v) noexcept {
            m_zenithAngle = v;
            return *this;
        }
        inline float zenithAngle() const noexcept {
            return m_zenithAngle;
        }
        inline Point& distance(const float &v) noexcept {
            m_distance = v;
            return *this;
        }
        inline float distance() const noexcept {
            return m_distance;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("distance"s), m_distance, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, visitor);
            doVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, visitor);
            doVisit(3, std::move("float"s), std::move("distance"s), m_distance, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("distance"s), m_distance, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_azimuthAngle{ 0.0f }; // field identifier = 1.
        float m_zenithAngle{ 0.0f }; // field identifier = 2.
        float m_distance{ 0.0f }; // field identifier = 3.
};
}}}

template<>
struct isVisitable<opendlv::logic::sensation::Point> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::sensation::Point> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_SENSATION_GEOLOCATION_HPP
#define OPENDLV_LOGIC_SENSATION_GEOLOCATION_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace sensation {
using namespace std::string_literals; // NOLINT
class LIB_API Geolocation {
    private:
        static constexpr const char* TheShortName = "Geolocation";
        static constexpr const char* TheLongName = "opendlv.logic.sensation.Geolocation";

    public:
        inline static int32_t ID() {
            return 1116;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        Geolocation() = default;
        Geolocation(const Geolocation&) = default;
        Geolocation& operator=(const Geolocation&) = default;
        Geolocation(Geolocation&&) = default;
        Geolocation& operator=(Geolocation&&) = default;
        ~Geolocation() = default;

    public:
        inline Geolocation& latitude(const double &v) noexcept {
            m_latitude = v;
            return *this;
        }
        inline double latitude() const noexcept {
            return m_latitude;
        }
        inline Geolocation& longitude(const double &v) noexcept {
            m_longitude = v;
            return *this;
        }
        inline double longitude() const noexcept {
            return m_longitude;
        }
        inline Geolocation& altitude(const float &v) noexcept {
            m_altitude = v;
            return *this;
        }
        inline float altitude() const noexcept {
            return m_altitude;
        }
        inline Geolocation& heading(const float &v) noexcept {
            m_heading = v;
            return *this;
        }
        inline float heading() const noexcept {
            return m_heading;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("double"s), std::move("latitude"s), m_latitude, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("double"s), std::move("longitude"s), m_longitude, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("altitude"s), m_altitude, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("float"s), std::move("heading"s), m_heading, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("double"s), std::move("latitude"s), m_latitude, visitor);
            doVisit(2, std::move("double"s), std::move("longitude"s), m_longitude, visitor);
            doVisit(3, std::move("float"s), std::move("altitude"s), m_altitude, visitor);
            doVisit(4, std::move("float"s), std::move("heading"s), m_heading, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("double"s), std::move("latitude"s), m_latitude, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("double"s), std::move("longitude"s), m_longitude, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("altitude"s), m_altitude, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("float"s), std::move("heading"s), m_heading, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        double m_latitude{ 0.0 }; // field identifier = 1.
        double m_longitude{ 0.0 }; // field identifier = 2.
        float m_altitude{ 0.0f }; // field identifier = 3.
        float m_heading{ 0.0f }; // field identifier = 4.
};
}}}

template<>
struct isVisitable<opendlv::logic::sensation::Geolocation> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::sensation::Geolocation> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_SENSATION_EQUILIBRIOCEPTION_HPP
#define OPENDLV_LOGIC_SENSATION_EQUILIBRIOCEPTION_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace sensation {
using namespace std::string_literals; // NOLINT
class LIB_API Equilibrioception {
    private:
        static constexpr const char* TheShortName = "Equilibrioception";
        static constexpr const char* TheLongName = "opendlv.logic.sensation.Equilibrioception";

    public:
        inline static int32_t ID() {
            return 1117;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        Equilibrioception() = default;
        Equilibrioception(const Equilibrioception&) = default;
        Equilibrioception& operator=(const Equilibrioception&) = default;
        Equilibrioception(Equilibrioception&&) = default;
        Equilibrioception& operator=(Equilibrioception&&) = default;
        ~Equilibrioception() = default;

    public:
        inline Equilibrioception& vx(const float &v) noexcept {
            m_vx = v;
            return *this;
        }
        inline float vx() const noexcept {
            return m_vx;
        }
        inline Equilibrioception& vy(const float &v) noexcept {
            m_vy = v;
            return *this;
        }
        inline float vy() const noexcept {
            return m_vy;
        }
        inline Equilibrioception& vz(const float &v) noexcept {
            m_vz = v;
            return *this;
        }
        inline float vz() const noexcept {
            return m_vz;
        }
        inline Equilibrioception& rollRate(const float &v) noexcept {
            m_rollRate = v;
            return *this;
        }
        inline float rollRate() const noexcept {
            return m_rollRate;
        }
        inline Equilibrioception& pitchRate(const float &v) noexcept {
            m_pitchRate = v;
            return *this;
        }
        inline float pitchRate() const noexcept {
            return m_pitchRate;
        }
        inline Equilibrioception& yawRate(const float &v) noexcept {
            m_yawRate = v;
            return *this;
        }
        inline float yawRate() const noexcept {
            return m_yawRate;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("vx"s), m_vx, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("vy"s), m_vy, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("vz"s), m_vz, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("float"s), std::move("rollRate"s), m_rollRate, visitor);
                return;
            }
            if (5 == fieldId) {
                doVisit(5, std::move("float"s), std::move("pitchRate"s), m_pitchRate, visitor);
                return;
            }
            if (6 == fieldId) {
                doVisit(6, std::move("float"s), std::move("yawRate"s), m_yawRate, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("vx"s), m_vx, visitor);
            doVisit(2, std::move("float"s), std::move("vy"s), m_vy, visitor);
            doVisit(3, std::move("float"s), std::move("vz"s), m_vz, visitor);
            doVisit(4, std::move("float"s), std::move("rollRate"s), m_rollRate, visitor);
            doVisit(5, std::move("float"s), std::move("pitchRate"s), m_pitchRate, visitor);
            doVisit(6, std::move("float"s), std::move("yawRate"s), m_yawRate, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("vx"s), m_vx, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("vy"s), m_vy, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("vz"s), m_vz, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("float"s), std::move("rollRate"s), m_rollRate, preVisit, visit, postVisit);
            doTripletForwardVisit(5, std::move("float"s), std::move("pitchRate"s), m_pitchRate, preVisit, visit, postVisit);
            doTripletForwardVisit(6, std::move("float"s), std::move("yawRate"s), m_yawRate, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_vx{ 0.0f }; // field identifier = 1.
        float m_vy{ 0.0f }; // field identifier = 2.
        float m_vz{ 0.0f }; // field identifier = 3.
        float m_rollRate{ 0.0f }; // field identifier = 4.
        float m_pitchRate{ 0.0f }; // field identifier = 5.
        float m_yawRate{ 0.0f }; // field identifier = 6.
};
}}}

template<>
struct isVisitable<opendlv::logic::sensation::Equilibrioception> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::sensation::Equilibrioception> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_SENSATION_ORIENTATION_HPP
#define OPENDLV_LOGIC_SENSATION_ORIENTATION_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace sensation {
using namespace std::string_literals; // NOLINT
class LIB_API Orientation {
    private:
        static constexpr const char* TheShortName = "Orientation";
        static constexpr const char* TheLongName = "opendlv.logic.sensation.Orientation";

    public:
        inline static int32_t ID() {
            return 1119;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        Orientation() = default;
        Orientation(const Orientation&) = default;
        Orientation& operator=(const Orientation&) = default;
        Orientation(Orientation&&) = default;
        Orientation& operator=(Orientation&&) = default;
        ~Orientation() = default;

    public:
        inline Orientation& qx(const float &v) noexcept {
            m_qx = v;
            return *this;
        }
        inline float qx() const noexcept {
            return m_qx;
        }
        inline Orientation& qy(const float &v) noexcept {
            m_qy = v;
            return *this;
        }
        inline float qy() const noexcept {
            return m_qy;
        }
        inline Orientation& qz(const float &v) noexcept {
            m_qz = v;
            return *this;
        }
        inline float qz() const noexcept {
            return m_qz;
        }
        inline Orientation& qw(const float &v) noexcept {
            m_qw = v;
            return *this;
        }
        inline float qw() const noexcept {
            return m_qw;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("qx"s), m_qx, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("qy"s), m_qy, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("qz"s), m_qz, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("float"s), std::move("qw"s), m_qw, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("qx"s), m_qx, visitor);
            doVisit(2, std::move("float"s), std::move("qy"s), m_qy, visitor);
            doVisit(3, std::move("float"s), std::move("qz"s), m_qz, visitor);
            doVisit(4, std::move("float"s), std::move("qw"s), m_qw, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("qx"s), m_qx, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("qy"s), m_qy, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("qz"s), m_qz, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("float"s), std::move("qw"s), m_qw, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_qx{ 0.0f }; // field identifier = 1.
        float m_qy{ 0.0f }; // field identifier = 2.
        float m_qz{ 0.0f }; // field identifier = 3.
        float m_qw{ 0.0f }; // field identifier = 4.
};
}}}

template<>
struct isVisitable<opendlv::logic::sensation::Orientation> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::sensation::Orientation> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_PERCEPTION_DETECTIONTYPE_HPP
#define OPENDLV_LOGIC_PERCEPTION_DETECTIONTYPE_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace perception {
using namespace std::string_literals; // NOLINT
class LIB_API DetectionType {
    private:
        static constexpr const char* TheShortName = "DetectionType";
        static constexpr const char* TheLongName = "opendlv.logic.perception.DetectionType";

    public:
        inline static int32_t ID() {
            return 1130;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        DetectionType() = default;
        DetectionType(const DetectionType&) = default;
        DetectionType& operator=(const DetectionType&) = default;
        DetectionType(DetectionType&&) = default;
        DetectionType& operator=(DetectionType&&) = default;
        ~DetectionType() = default;

    public:
        inline DetectionType& sampleId(const uint32_t &v) noexcept {
            m_sampleId = v;
            return *this;
        }
        inline uint32_t sampleId() const noexcept {
            return m_sampleId;
        }
        inline DetectionType& detectionId(const uint32_t &v) noexcept {
            m_detectionId = v;
            return *this;
        }
        inline uint32_t detectionId() const noexcept {
            return m_detectionId;
        }
        inline DetectionType& type(const uint32_t &v) noexcept {
            m_type = v;
            return *this;
        }
        inline uint32_t type() const noexcept {
            return m_type;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("uint32_t"s), std::move("detectionId"s), m_detectionId, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("uint32_t"s), std::move("type"s), m_type, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, visitor);
            doVisit(2, std::move("uint32_t"s), std::move("detectionId"s), m_detectionId, visitor);
            doVisit(3, std::move("uint32_t"s), std::move("type"s), m_type, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("uint32_t"s), std::move("detectionId"s), m_detectionId, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("uint32_t"s), std::move("type"s), m_type, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        uint32_t m_sampleId{ 0 }; // field identifier = 1.
        uint32_t m_detectionId{ 0 }; // field identifier = 2.
        uint32_t m_type{ 0 }; // field identifier = 3.
};
}}}

template<>
struct isVisitable<opendlv::logic::perception::DetectionType> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::perception::DetectionType> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_PERCEPTION_DETECTIONPROPERTY_HPP
#define OPENDLV_LOGIC_PERCEPTION_DETECTIONPROPERTY_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace perception {
using namespace std::string_literals; // NOLINT
class LIB_API DetectionProperty {
    private:
        static constexpr const char* TheShortName = "DetectionProperty";
        static constexpr const char* TheLongName = "opendlv.logic.perception.DetectionProperty";

    public:
        inline static int32_t ID() {
            return 1131;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        DetectionProperty() = default;
        DetectionProperty(const DetectionProperty&) = default;
        DetectionProperty& operator=(const DetectionProperty&) = default;
        DetectionProperty(DetectionProperty&&) = default;
        DetectionProperty& operator=(DetectionProperty&&) = default;
        ~DetectionProperty() = default;

    public:
        inline DetectionProperty& sampleId(const uint32_t &v) noexcept {
            m_sampleId = v;
            return *this;
        }
        inline uint32_t sampleId() const noexcept {
            return m_sampleId;
        }
        inline DetectionProperty& detectionId(const uint32_t &v) noexcept {
            m_detectionId = v;
            return *this;
        }
        inline uint32_t detectionId() const noexcept {
            return m_detectionId;
        }
        inline DetectionProperty& property(const std::string &v) noexcept {
            m_property = v;
            return *this;
        }
        inline std::string property() const noexcept {
            return m_property;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("uint32_t"s), std::move("detectionId"s), m_detectionId, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("std::string"s), std::move("property"s), m_property, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, visitor);
            doVisit(2, std::move("uint32_t"s), std::move("detectionId"s), m_detectionId, visitor);
            doVisit(3, std::move("std::string"s), std::move("property"s), m_property, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("uint32_t"s), std::move("detectionId"s), m_detectionId, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("std::string"s), std::move("property"s), m_property, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        uint32_t m_sampleId{ 0 }; // field identifier = 1.
        uint32_t m_detectionId{ 0 }; // field identifier = 2.
        std::string m_property{ ""s }; // field identifier = 3.
};
}}}

template<>
struct isVisitable<opendlv::logic::perception::DetectionProperty> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::perception::DetectionProperty> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_PERCEPTION_DETECTIONDIRECTION_HPP
#define OPENDLV_LOGIC_PERCEPTION_DETECTIONDIRECTION_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace perception {
using namespace std::string_literals; // NOLINT
class LIB_API DetectionDirection {
    private:
        static constexpr const char* TheShortName = "DetectionDirection";
        static constexpr const char* TheLongName = "opendlv.logic.perception.DetectionDirection";

    public:
        inline static int32_t ID() {
            return 1132;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        DetectionDirection() = default;
        DetectionDirection(const DetectionDirection&) = default;
        DetectionDirection& operator=(const DetectionDirection&) = default;
        DetectionDirection(DetectionDirection&&) = default;
        DetectionDirection& operator=(DetectionDirection&&) = default;
        ~DetectionDirection() = default;

    public:
        inline DetectionDirection& sampleId(const uint32_t &v) noexcept {
            m_sampleId = v;
            return *this;
        }
        inline uint32_t sampleId() const noexcept {
            return m_sampleId;
        }
        inline DetectionDirection& detectionId(const uint32_t &v) noexcept {
            m_detectionId = v;
            return *this;
        }
        inline uint32_t detectionId() const noexcept {
            return m_detectionId;
        }
        inline DetectionDirection& azimuthAngle(const float &v) noexcept {
            m_azimuthAngle = v;
            return *this;
        }
        inline float azimuthAngle() const noexcept {
            return m_azimuthAngle;
        }
        inline DetectionDirection& zenithAngle(const float &v) noexcept {
            m_zenithAngle = v;
            return *this;
        }
        inline float zenithAngle() const noexcept {
            return m_zenithAngle;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("uint32_t"s), std::move("detectionId"s), m_detectionId, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, visitor);
            doVisit(2, std::move("uint32_t"s), std::move("detectionId"s), m_detectionId, visitor);
            doVisit(3, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, visitor);
            doVisit(4, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("uint32_t"s), std::move("detectionId"s), m_detectionId, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        uint32_t m_sampleId{ 0 }; // field identifier = 1.
        uint32_t m_detectionId{ 0 }; // field identifier = 2.
        float m_azimuthAngle{ 0.0f }; // field identifier = 3.
        float m_zenithAngle{ 0.0f }; // field identifier = 4.
};
}}}

template<>
struct isVisitable<opendlv::logic::perception::DetectionDirection> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::perception::DetectionDirection> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_PERCEPTION_DETECTIONDISTANCE_HPP
#define OPENDLV_LOGIC_PERCEPTION_DETECTIONDISTANCE_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace perception {
using namespace std::string_literals; // NOLINT
class LIB_API DetectionDistance {
    private:
        static constexpr const char* TheShortName = "DetectionDistance";
        static constexpr const char* TheLongName = "opendlv.logic.perception.DetectionDistance";

    public:
        inline static int32_t ID() {
            return 1133;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        DetectionDistance() = default;
        DetectionDistance(const DetectionDistance&) = default;
        DetectionDistance& operator=(const DetectionDistance&) = default;
        DetectionDistance(DetectionDistance&&) = default;
        DetectionDistance& operator=(DetectionDistance&&) = default;
        ~DetectionDistance() = default;

    public:
        inline DetectionDistance& sampleId(const uint32_t &v) noexcept {
            m_sampleId = v;
            return *this;
        }
        inline uint32_t sampleId() const noexcept {
            return m_sampleId;
        }
        inline DetectionDistance& detectionId(const uint32_t &v) noexcept {
            m_detectionId = v;
            return *this;
        }
        inline uint32_t detectionId() const noexcept {
            return m_detectionId;
        }
        inline DetectionDistance& distance(const float &v) noexcept {
            m_distance = v;
            return *this;
        }
        inline float distance() const noexcept {
            return m_distance;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("uint32_t"s), std::move("detectionId"s), m_detectionId, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("distance"s), m_distance, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, visitor);
            doVisit(2, std::move("uint32_t"s), std::move("detectionId"s), m_detectionId, visitor);
            doVisit(3, std::move("float"s), std::move("distance"s), m_distance, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("uint32_t"s), std::move("detectionId"s), m_detectionId, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("distance"s), m_distance, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        uint32_t m_sampleId{ 0 }; // field identifier = 1.
        uint32_t m_detectionId{ 0 }; // field identifier = 2.
        float m_distance{ 0.0f }; // field identifier = 3.
};
}}}

template<>
struct isVisitable<opendlv::logic::perception::DetectionDistance> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::perception::DetectionDistance> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_PERCEPTION_DETECTIONBOUNDINGBOX_HPP
#define OPENDLV_LOGIC_PERCEPTION_DETECTIONBOUNDINGBOX_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace perception {
using namespace std::string_literals; // NOLINT
class LIB_API DetectionBoundingBox {
    private:
        static constexpr const char* TheShortName = "DetectionBoundingBox";
        static constexpr const char* TheLongName = "opendlv.logic.perception.DetectionBoundingBox";

    public:
        inline static int32_t ID() {
            return 1134;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        DetectionBoundingBox() = default;
        DetectionBoundingBox(const DetectionBoundingBox&) = default;
        DetectionBoundingBox& operator=(const DetectionBoundingBox&) = default;
        DetectionBoundingBox(DetectionBoundingBox&&) = default;
        DetectionBoundingBox& operator=(DetectionBoundingBox&&) = default;
        ~DetectionBoundingBox() = default;

    public:
        inline DetectionBoundingBox& sampleId(const uint32_t &v) noexcept {
            m_sampleId = v;
            return *this;
        }
        inline uint32_t sampleId() const noexcept {
            return m_sampleId;
        }
        inline DetectionBoundingBox& detectionId(const uint32_t &v) noexcept {
            m_detectionId = v;
            return *this;
        }
        inline uint32_t detectionId() const noexcept {
            return m_detectionId;
        }
        inline DetectionBoundingBox& x(const float &v) noexcept {
            m_x = v;
            return *this;
        }
        inline float x() const noexcept {
            return m_x;
        }
        inline DetectionBoundingBox& y(const float &v) noexcept {
            m_y = v;
            return *this;
        }
        inline float y() const noexcept {
            return m_y;
        }
        inline DetectionBoundingBox& width(const float &v) noexcept {
            m_width = v;
            return *this;
        }
        inline float width() const noexcept {
            return m_width;
        }
        inline DetectionBoundingBox& height(const float &v) noexcept {
            m_height = v;
            return *this;
        }
        inline float height() const noexcept {
            return m_height;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("uint32_t"s), std::move("detectionId"s), m_detectionId, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("x"s), m_x, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("float"s), std::move("y"s), m_y, visitor);
                return;
            }
            if (5 == fieldId) {
                doVisit(5, std::move("float"s), std::move("width"s), m_width, visitor);
                return;
            }
            if (6 == fieldId) {
                doVisit(6, std::move("float"s), std::move("height"s), m_height, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, visitor);
            doVisit(2, std::move("uint32_t"s), std::move("detectionId"s), m_detectionId, visitor);
            doVisit(3, std::move("float"s), std::move("x"s), m_x, visitor);
            doVisit(4, std::move("float"s), std::move("y"s), m_y, visitor);
            doVisit(5, std::move("float"s), std::move("width"s), m_width, visitor);
            doVisit(6, std::move("float"s), std::move("height"s), m_height, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("uint32_t"s), std::move("detectionId"s), m_detectionId, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("x"s), m_x, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("float"s), std::move("y"s), m_y, preVisit, visit, postVisit);
            doTripletForwardVisit(5, std::move("float"s), std::move("width"s), m_width, preVisit, visit, postVisit);
            doTripletForwardVisit(6, std::move("float"s), std::move("height"s), m_height, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        uint32_t m_sampleId{ 0 }; // field identifier = 1.
        uint32_t m_detectionId{ 0 }; // field identifier = 2.
        float m_x{ 0.0f }; // field identifier = 3.
        float m_y{ 0.0f }; // field identifier = 4.
        float m_width{ 0.0f }; // field identifier = 5.
        float m_height{ 0.0f }; // field identifier = 6.
};
}}}

template<>
struct isVisitable<opendlv::logic::perception::DetectionBoundingBox> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::perception::DetectionBoundingBox> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_PERCEPTION_DETECTIONPOSITION_HPP
#define OPENDLV_LOGIC_PERCEPTION_DETECTIONPOSITION_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace perception {
using namespace std::string_literals; // NOLINT
class LIB_API DetectionPosition {
    private:
        static constexpr const char* TheShortName = "DetectionPosition";
        static constexpr const char* TheLongName = "opendlv.logic.perception.DetectionPosition";

    public:
        inline static int32_t ID() {
            return 1135;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        DetectionPosition() = default;
        DetectionPosition(const DetectionPosition&) = default;
        DetectionPosition& operator=(const DetectionPosition&) = default;
        DetectionPosition(DetectionPosition&&) = default;
        DetectionPosition& operator=(DetectionPosition&&) = default;
        ~DetectionPosition() = default;

    public:
        inline DetectionPosition& sampleId(const uint32_t &v) noexcept {
            m_sampleId = v;
            return *this;
        }
        inline uint32_t sampleId() const noexcept {
            return m_sampleId;
        }
        inline DetectionPosition& detectionId(const uint32_t &v) noexcept {
            m_detectionId = v;
            return *this;
        }
        inline uint32_t detectionId() const noexcept {
            return m_detectionId;
        }
        inline DetectionPosition& x(const float &v) noexcept {
            m_x = v;
            return *this;
        }
        inline float x() const noexcept {
            return m_x;
        }
        inline DetectionPosition& y(const float &v) noexcept {
            m_y = v;
            return *this;
        }
        inline float y() const noexcept {
            return m_y;
        }
        inline DetectionPosition& z(const float &v) noexcept {
            m_z = v;
            return *this;
        }
        inline float z() const noexcept {
            return m_z;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("uint32_t"s), std::move("detectionId"s), m_detectionId, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("x"s), m_x, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("float"s), std::move("y"s), m_y, visitor);
                return;
            }
            if (5 == fieldId) {
                doVisit(5, std::move("float"s), std::move("z"s), m_z, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, visitor);
            doVisit(2, std::move("uint32_t"s), std::move("detectionId"s), m_detectionId, visitor);
            doVisit(3, std::move("float"s), std::move("x"s), m_x, visitor);
            doVisit(4, std::move("float"s), std::move("y"s), m_y, visitor);
            doVisit(5, std::move("float"s), std::move("z"s), m_z, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("uint32_t"s), std::move("detectionId"s), m_detectionId, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("x"s), m_x, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("float"s), std::move("y"s), m_y, preVisit, visit, postVisit);
            doTripletForwardVisit(5, std::move("float"s), std::move("z"s), m_z, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        uint32_t m_sampleId{ 0 }; // field identifier = 1.
        uint32_t m_detectionId{ 0 }; // field identifier = 2.
        float m_x{ 0.0f }; // field identifier = 3.
        float m_y{ 0.0f }; // field identifier = 4.
        float m_z{ 0.0f }; // field identifier = 5.
};
}}}

template<>
struct isVisitable<opendlv::logic::perception::DetectionPosition> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::perception::DetectionPosition> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_PERCEPTION_DETECTIONSURFACE_HPP
#define OPENDLV_LOGIC_PERCEPTION_DETECTIONSURFACE_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace perception {
using namespace std::string_literals; // NOLINT
class LIB_API DetectionSurface {
    private:
        static constexpr const char* TheShortName = "DetectionSurface";
        static constexpr const char* TheLongName = "opendlv.logic.perception.DetectionSurface";

    public:
        inline static int32_t ID() {
            return 1136;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        DetectionSurface() = default;
        DetectionSurface(const DetectionSurface&) = default;
        DetectionSurface& operator=(const DetectionSurface&) = default;
        DetectionSurface(DetectionSurface&&) = default;
        DetectionSurface& operator=(DetectionSurface&&) = default;
        ~DetectionSurface() = default;

    public:
        inline DetectionSurface& sampleId(const uint32_t &v) noexcept {
            m_sampleId = v;
            return *this;
        }
        inline uint32_t sampleId() const noexcept {
            return m_sampleId;
        }
        inline DetectionSurface& detectionId(const uint32_t &v) noexcept {
            m_detectionId = v;
            return *this;
        }
        inline uint32_t detectionId() const noexcept {
            return m_detectionId;
        }
        inline DetectionSurface& format(const std::string &v) noexcept {
            m_format = v;
            return *this;
        }
        inline std::string format() const noexcept {
            return m_format;
        }
        inline DetectionSurface& data(const std::string &v) noexcept {
            m_data = v;
            return *this;
        }
        inline std::string data() const noexcept {
            return m_data;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("uint32_t"s), std::move("detectionId"s), m_detectionId, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("std::string"s), std::move("format"s), m_format, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("std::string"s), std::move("data"s), m_data, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, visitor);
            doVisit(2, std::move("uint32_t"s), std::move("detectionId"s), m_detectionId, visitor);
            doVisit(3, std::move("std::string"s), std::move("format"s), m_format, visitor);
            doVisit(4, std::move("std::string"s), std::move("data"s), m_data, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("uint32_t"s), std::move("sampleId"s), m_sampleId, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("uint32_t"s), std::move("detectionId"s), m_detectionId, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("std::string"s), std::move("format"s), m_format, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("std::string"s), std::move("data"s), m_data, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        uint32_t m_sampleId{ 0 }; // field identifier = 1.
        uint32_t m_detectionId{ 0 }; // field identifier = 2.
        std::string m_format{ ""s }; // field identifier = 3.
        std::string m_data{ ""s }; // field identifier = 4.
};
}}}

template<>
struct isVisitable<opendlv::logic::perception::DetectionSurface> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::perception::DetectionSurface> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_ACTION_AIMDIRECTION_HPP
#define OPENDLV_LOGIC_ACTION_AIMDIRECTION_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace action {
using namespace std::string_literals; // NOLINT
class LIB_API AimDirection {
    private:
        static constexpr const char* TheShortName = "AimDirection";
        static constexpr const char* TheLongName = "opendlv.logic.action.AimDirection";

    public:
        inline static int32_t ID() {
            return 1171;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        AimDirection() = default;
        AimDirection(const AimDirection&) = default;
        AimDirection& operator=(const AimDirection&) = default;
        AimDirection(AimDirection&&) = default;
        AimDirection& operator=(AimDirection&&) = default;
        ~AimDirection() = default;

    public:
        inline AimDirection& azimuthAngle(const float &v) noexcept {
            m_azimuthAngle = v;
            return *this;
        }
        inline float azimuthAngle() const noexcept {
            return m_azimuthAngle;
        }
        inline AimDirection& zenithAngle(const float &v) noexcept {
            m_zenithAngle = v;
            return *this;
        }
        inline float zenithAngle() const noexcept {
            return m_zenithAngle;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, visitor);
            doVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_azimuthAngle{ 0.0f }; // field identifier = 1.
        float m_zenithAngle{ 0.0f }; // field identifier = 2.
};
}}}

template<>
struct isVisitable<opendlv::logic::action::AimDirection> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::action::AimDirection> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_ACTION_AIMPOINT_HPP
#define OPENDLV_LOGIC_ACTION_AIMPOINT_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace action {
using namespace std::string_literals; // NOLINT
class LIB_API AimPoint {
    private:
        static constexpr const char* TheShortName = "AimPoint";
        static constexpr const char* TheLongName = "opendlv.logic.action.AimPoint";

    public:
        inline static int32_t ID() {
            return 1172;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        AimPoint() = default;
        AimPoint(const AimPoint&) = default;
        AimPoint& operator=(const AimPoint&) = default;
        AimPoint(AimPoint&&) = default;
        AimPoint& operator=(AimPoint&&) = default;
        ~AimPoint() = default;

    public:
        inline AimPoint& azimuthAngle(const float &v) noexcept {
            m_azimuthAngle = v;
            return *this;
        }
        inline float azimuthAngle() const noexcept {
            return m_azimuthAngle;
        }
        inline AimPoint& zenithAngle(const float &v) noexcept {
            m_zenithAngle = v;
            return *this;
        }
        inline float zenithAngle() const noexcept {
            return m_zenithAngle;
        }
        inline AimPoint& distance(const float &v) noexcept {
            m_distance = v;
            return *this;
        }
        inline float distance() const noexcept {
            return m_distance;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("distance"s), m_distance, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, visitor);
            doVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, visitor);
            doVisit(3, std::move("float"s), std::move("distance"s), m_distance, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("distance"s), m_distance, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_azimuthAngle{ 0.0f }; // field identifier = 1.
        float m_zenithAngle{ 0.0f }; // field identifier = 2.
        float m_distance{ 0.0f }; // field identifier = 3.
};
}}}

template<>
struct isVisitable<opendlv::logic::action::AimPoint> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::action::AimPoint> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_ACTION_PREVIEWPOINT_HPP
#define OPENDLV_LOGIC_ACTION_PREVIEWPOINT_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace action {
using namespace std::string_literals; // NOLINT
class LIB_API PreviewPoint {
    private:
        static constexpr const char* TheShortName = "PreviewPoint";
        static constexpr const char* TheLongName = "opendlv.logic.action.PreviewPoint";

    public:
        inline static int32_t ID() {
            return 1173;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        PreviewPoint() = default;
        PreviewPoint(const PreviewPoint&) = default;
        PreviewPoint& operator=(const PreviewPoint&) = default;
        PreviewPoint(PreviewPoint&&) = default;
        PreviewPoint& operator=(PreviewPoint&&) = default;
        ~PreviewPoint() = default;

    public:
        inline PreviewPoint& azimuthAngle(const float &v) noexcept {
            m_azimuthAngle = v;
            return *this;
        }
        inline float azimuthAngle() const noexcept {
            return m_azimuthAngle;
        }
        inline PreviewPoint& zenithAngle(const float &v) noexcept {
            m_zenithAngle = v;
            return *this;
        }
        inline float zenithAngle() const noexcept {
            return m_zenithAngle;
        }
        inline PreviewPoint& distance(const float &v) noexcept {
            m_distance = v;
            return *this;
        }
        inline float distance() const noexcept {
            return m_distance;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("distance"s), m_distance, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, visitor);
            doVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, visitor);
            doVisit(3, std::move("float"s), std::move("distance"s), m_distance, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("distance"s), m_distance, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_azimuthAngle{ 0.0f }; // field identifier = 1.
        float m_zenithAngle{ 0.0f }; // field identifier = 2.
        float m_distance{ 0.0f }; // field identifier = 3.
};
}}}

template<>
struct isVisitable<opendlv::logic::action::PreviewPoint> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::action::PreviewPoint> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_ACTION_GLOBALPATH_HPP
#define OPENDLV_LOGIC_ACTION_GLOBALPATH_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace action {
using namespace std::string_literals; // NOLINT
class LIB_API GlobalPath {
    private:
        static constexpr const char* TheShortName = "GlobalPath";
        static constexpr const char* TheLongName = "opendlv.logic.action.GlobalPath";

    public:
        inline static int32_t ID() {
            return 1180;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        GlobalPath() = default;
        GlobalPath(const GlobalPath&) = default;
        GlobalPath& operator=(const GlobalPath&) = default;
        GlobalPath(GlobalPath&&) = default;
        GlobalPath& operator=(GlobalPath&&) = default;
        ~GlobalPath() = default;

    public:
        inline GlobalPath& format(const std::string &v) noexcept {
            m_format = v;
            return *this;
        }
        inline std::string format() const noexcept {
            return m_format;
        }
        inline GlobalPath& count(const uint32_t &v) noexcept {
            m_count = v;
            return *this;
        }
        inline uint32_t count() const noexcept {
            return m_count;
        }
        inline GlobalPath& data(const std::string &v) noexcept {
            m_data = v;
            return *this;
        }
        inline std::string data() const noexcept {
            return m_data;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("std::string"s), std::move("format"s), m_format, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("uint32_t"s), std::move("count"s), m_count, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("std::string"s), std::move("data"s), m_data, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("std::string"s), std::move("format"s), m_format, visitor);
            doVisit(2, std::move("uint32_t"s), std::move("count"s), m_count, visitor);
            doVisit(3, std::move("std::string"s), std::move("data"s), m_data, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("std::string"s), std::move("format"s), m_format, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("uint32_t"s), std::move("count"s), m_count, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("std::string"s), std::move("data"s), m_data, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        std::string m_format{ ""s }; // field identifier = 1.
        uint32_t m_count{ 0 }; // field identifier = 2.
        std::string m_data{ ""s }; // field identifier = 3.
};
}}}

template<>
struct isVisitable<opendlv::logic::action::GlobalPath> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::action::GlobalPath> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_ACTION_LOCALPATH_HPP
#define OPENDLV_LOGIC_ACTION_LOCALPATH_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace action {
using namespace std::string_literals; // NOLINT
class LIB_API LocalPath {
    private:
        static constexpr const char* TheShortName = "LocalPath";
        static constexpr const char* TheLongName = "opendlv.logic.action.LocalPath";

    public:
        inline static int32_t ID() {
            return 1181;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        LocalPath() = default;
        LocalPath(const LocalPath&) = default;
        LocalPath& operator=(const LocalPath&) = default;
        LocalPath(LocalPath&&) = default;
        LocalPath& operator=(LocalPath&&) = default;
        ~LocalPath() = default;

    public:
        inline LocalPath& format(const std::string &v) noexcept {
            m_format = v;
            return *this;
        }
        inline std::string format() const noexcept {
            return m_format;
        }
        inline LocalPath& count(const uint32_t &v) noexcept {
            m_count = v;
            return *this;
        }
        inline uint32_t count() const noexcept {
            return m_count;
        }
        inline LocalPath& data(const std::string &v) noexcept {
            m_data = v;
            return *this;
        }
        inline std::string data() const noexcept {
            return m_data;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("std::string"s), std::move("format"s), m_format, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("uint32_t"s), std::move("count"s), m_count, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("std::string"s), std::move("data"s), m_data, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("std::string"s), std::move("format"s), m_format, visitor);
            doVisit(2, std::move("uint32_t"s), std::move("count"s), m_count, visitor);
            doVisit(3, std::move("std::string"s), std::move("data"s), m_data, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("std::string"s), std::move("format"s), m_format, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("uint32_t"s), std::move("count"s), m_count, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("std::string"s), std::move("data"s), m_data, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        std::string m_format{ ""s }; // field identifier = 1.
        uint32_t m_count{ 0 }; // field identifier = 2.
        std::string m_data{ ""s }; // field identifier = 3.
};
}}}

template<>
struct isVisitable<opendlv::logic::action::LocalPath> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::action::LocalPath> {
    static const bool value = true;
};
#endif

