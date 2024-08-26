#ifndef HMDEFINEMEMBER_H
#define HMDEFINEMEMBER_H

#define HM_DEFINE_MEMBER(type, name)             \
  private:                                       \
    type m_##name;                               \
                                                 \
  public:                                        \
    type get_##name() const { return m_##name; } \
    void set_##name(const type &value) { m_##name = value; }

#define HM_DEFINE_GETTER(type, name) \
    type get_##name() const { return m_##name; }

#define HM_DEFINE_SETTER(type, name) \
    void set_##name(const type &value) { m_##name = value; }

#define HM_DEFINE_GETTER_SETTER(type, name) \
    HM_DEFINE_GETTER(type, name)            \
    HM_DEFINE_SETTER(type, name)

#endif