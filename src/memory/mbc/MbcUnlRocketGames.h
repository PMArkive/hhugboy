/*
 * Additional mapper support for hhugboy emulator
 * by NewRisingSun 2020
 * This file released under Creative Commons CC0 https://creativecommons.org/publicdomain/zero/1.0/legalcode
 *
 * As part of the hhugboy project it is also licensed under the GNU General Public License v2
 * See "license.txt" in the project root
 */

#ifndef HHUGBOY_MBCUNLROCKETGAMES_H
#define HHUGBOY_MBCUNLROCKETGAMES_H


#include "BasicMbc.h"
class MbcUnlRocketGames : public BasicMbc {
public:
        virtual byte readMemory(unsigned short address) override;
	virtual void writeMemory(unsigned short address, register byte data) override;
	virtual void signalMemoryWrite(unsigned short address, register byte data) override;
        virtual void resetVars(bool preserveMulticartState) override;
        virtual void readMbcSpecificVarsFromStateFile(FILE *statefile) override;
        virtual void writeMbcSpecificVarsToStateFile(FILE *statefile) override;
private:
	byte	outerBank;
	byte	mode;
	byte	unlockCount;
};


#endif //HHUGBOY_MBCUNLROCKETGAMES_H
