#ifndef MISC_BASE_CONSTRUCTORMAGIC_H
#define MISC_BASE_CONSTRUCTORMAGIC_H

#define MISC_DISALLOW_ASSIGN(TypeName) \
  TypeName& operator(const TypeName&) = delete

#define MISC_DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&) = delete; \
  MISC_DISALLOW_ASSIGN(TypeName)

#define MISC_DISALLOW_IMPLICIT_CONSTRUCTORS(TypeName) \
  TypeName() = delete; \
  MISC_DISALLOW_COPY_AND_ASSIGN(TypeName)

#endif