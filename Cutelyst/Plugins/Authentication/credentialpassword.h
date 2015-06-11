/*
 * Copyright (C) 2013-2014 Daniel Nicoletti <dantti12@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB. If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef CUTELYSTPLUGIN_CREDENTIALPASSWORD_H
#define CUTELYSTPLUGIN_CREDENTIALPASSWORD_H

#include <Cutelyst/Plugins/authentication.h>
#include <QCryptographicHash>

namespace Cutelyst {

class CredentialPasswordPrivate;
class CredentialPassword : public AuthenticationCredential
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(CredentialPassword)
public:
    enum Type {
        None,
        Clear,
        Hashed,
        SelfCheck
    };
    explicit CredentialPassword(QObject *parent = 0);
    virtual ~CredentialPassword();

    AuthenticationUser authenticate(Context *c, AuthenticationRealm *realm, const CStringHash &authinfo) Q_DECL_FINAL;

    QString passwordField() const;
    void setPasswordField(const QString &fieldName);

    Type passwordType() const;
    void setPasswordType(Type type);

    QCryptographicHash::Algorithm hashType() const;
    void setHashType(QCryptographicHash::Algorithm type);

    QString passwordPreSalt() const;
    void setPasswordPreSalt(const QString &passwordPreSalt);

    QString passwordPostSalt() const;
    void setPasswordPostSalt(const QString &passwordPostSalt);

protected:
    CredentialPasswordPrivate *d_ptr;
};

} // namespace Plugin

#endif // CUTELYSTPLUGIN_CREDENTIALPASSWORD_H
