/*
 * Copyright (C) 2025, Stephan Mueller <smueller@chronox.de>
 *
 * License: see LICENSE file in root directory
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ALL OF
 * WHICH ARE HEREBY DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF NOT ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 */
/*
 * Test vectors are obtained from
 * https://pages.nist.gov/ACVP/draft-celi-acvp-ml-dsa.html#name-known-answer-tests
 */

#ifndef DILITHIUM_REJECTION_UPSTREAM_VECTORS_65_H
#define DILITHIUM_REJECTION_UPSTREAM_VECTORS_65_H

#include "dilithium_type.h"

#ifdef __cplusplus
extern "C" {
#endif

struct dilithium_rejection_testvector {
	uint8_t seed[LC_DILITHIUM_SEEDBYTES];
	uint8_t pk[LC_DILITHIUM_PUBLICKEYBYTES];
	uint8_t sk[LC_DILITHIUM_SECRETKEYBYTES];
	uint8_t key_hash[LC_SHA256_SIZE_DIGEST];
	uint8_t msg[32];
	uint8_t sig_hash[LC_SHA256_SIZE_DIGEST];
	uint8_t sig[LC_DILITHIUM_CRYPTO_BYTES];
};

static const struct dilithium_rejection_testvector dilithium_rejection_testvectors[] = {
	{
		/* Data from Table 1 */
		.seed = { 0xCC, 0xD6, 0x19, 0x17, 0x2D, 0x09, 0x78, 0xFD,
			  0xB5, 0x84, 0xD4, 0x33, 0xCB, 0x5A, 0x04, 0x4C,
			  0x8D, 0x24, 0x59, 0x2D, 0xAD, 0x4D, 0x1E, 0x57,
			  0xEC, 0xF1, 0xFD, 0x62, 0xC4, 0x0A, 0x30, 0x9B },
		.key_hash = { 0x75, 0x6C, 0x73, 0x4D, 0xB0, 0x13, 0xF8, 0x3E,
			      0x29, 0x5F, 0x28, 0x78, 0xB3, 0x2F, 0x16, 0x33,
			      0x5D, 0x57, 0x62, 0x49, 0xB1, 0x6D, 0x83, 0xAF,
			      0xED, 0xE1, 0xF5, 0xD4, 0xCC, 0x36, 0xD2, 0x4F },
		.msg = { 0x8A, 0x32, 0xD4, 0xB5, 0xD3, 0xC8, 0x53, 0x7A,
			 0xA9, 0xC7, 0xC9, 0x52, 0xF6, 0x39, 0x59, 0xC6,
			 0x61, 0x62, 0xA6, 0x8D, 0x5F, 0x3D, 0x02, 0xE6,
			 0xC5, 0xF9, 0x6E, 0x2C, 0xEA, 0x41, 0xD2, 0xEF },
		.sig_hash = { 0x95, 0x82, 0x87, 0xF1, 0x64, 0x6D, 0x85, 0x5B,
			      0xB0, 0x65, 0x89, 0x5A, 0x6C, 0x6D, 0xA3, 0xDF,
			      0x6A, 0x3F, 0x7A, 0xB2, 0xA4, 0x30, 0xC9, 0xDC,
			      0x55, 0x9D, 0x31, 0x3E, 0x7D, 0xD0, 0xA5, 0x27 },
	},
	{
		.seed = { 0xC6, 0x31, 0x5F, 0xC7, 0x19, 0x89, 0x5D, 0x16,
			  0x45, 0x4B, 0x7D, 0x62, 0x08, 0x4F, 0x0C, 0x8A,
			  0x29, 0x03, 0xD8, 0xD0, 0x0D, 0xC1, 0xD8, 0x2E,
			  0xB3, 0xF4, 0x5F, 0x06, 0x46, 0x3C, 0x6F, 0xBD },
		.key_hash = { 0xCE, 0xE1, 0xA1, 0xC7, 0xF9, 0x66, 0xA4, 0x11,
			      0xBB, 0x94, 0xC3, 0x8A, 0x0E, 0x33, 0xE1, 0xF7,
			      0x10, 0x2D, 0x31, 0x30, 0xFA, 0x9C, 0x5D, 0x27,
			      0x96, 0xF3, 0xF7, 0xF8, 0x6E, 0xCF, 0x4B, 0x1D },
		.msg = { 0xD8, 0xCB, 0x8B, 0x23, 0x93, 0x14, 0x95, 0xFD,
			 0xF7, 0x14, 0x77, 0xDB, 0x7C, 0x33, 0x5A, 0x15,
			 0x1C, 0x6A, 0x90, 0x96, 0x97, 0xF1, 0xC3, 0x9A,
			 0x31, 0x75, 0x13, 0x3B, 0x68, 0x88, 0x1F, 0x28 },
		.sig_hash = { 0xBD, 0x57, 0xA9, 0x32, 0x31, 0xEF, 0xEF, 0x6B,
			      0x4E, 0x7F, 0xE3, 0x74, 0xE2, 0x19, 0x4D, 0xB7,
			      0xE0, 0x02, 0x02, 0xEA, 0xF5, 0xEF, 0xC6, 0x0D,
			      0xF5, 0xF9, 0xFE, 0x1C, 0x5F, 0x57, 0x9D, 0x06 },
	},
	{
		.seed = { 0xF0, 0x05, 0xE4, 0x73, 0x8B, 0x52, 0x8F, 0x95,
			  0x36, 0x69, 0xA2, 0xBC, 0xA3, 0x92, 0x52, 0x66,
			  0xDB, 0xD2, 0x39, 0x09, 0xCD, 0x2C, 0x4D, 0xCE,
			  0x50, 0xB9, 0x80, 0xD7, 0x89, 0xEB, 0xD0, 0xD4 },
		.key_hash = { 0xD3, 0xE3, 0x35, 0x02, 0xCC, 0xC0, 0x35, 0xC9,
			      0xB9, 0x19, 0x5A, 0x27, 0x14, 0xFE, 0x7E, 0xCE,
			      0xDD, 0x13, 0xDF, 0xF4, 0xB8, 0x54, 0xF2, 0x37,
			      0x6D, 0x99, 0x3D, 0x38, 0xA8, 0xE8, 0xAF, 0xF2 },
		.msg = { 0xEF, 0x1F, 0xE0, 0x25, 0xF8, 0xDF, 0x1F, 0xDC,
			 0xFD, 0xAF, 0xD1, 0x88, 0xF6, 0x8B, 0x9D, 0x10,
			 0x85, 0xAE, 0x8D, 0x09, 0x23, 0x4E, 0xBD, 0xAD,
			 0x67, 0xDE, 0x98, 0x5B, 0xA7, 0x34, 0x7D, 0xE4 },
		.sig_hash = { 0x9E, 0x7B, 0x66, 0x8C, 0x51, 0xB2, 0x50, 0xB1,
			      0x2E, 0xD7, 0x66, 0x65, 0xBB, 0x43, 0x15, 0xCE,
			      0x4B, 0xDB, 0xAF, 0x00, 0xBF, 0x92, 0x7F, 0x6D,
			      0x89, 0x5F, 0x06, 0x01, 0x0D, 0x3B, 0xBC, 0x0E },
	},
	{
		.seed = { 0xF2, 0x15, 0xBA, 0x22, 0x80, 0xD8, 0x6F, 0x14,
			  0x20, 0x12, 0xFC, 0x05, 0xFF, 0xC0, 0x4F, 0x2C,
			  0x7D, 0x22, 0xFF, 0x5D, 0xD7, 0xD6, 0x9A, 0xA0,
			  0xEF, 0xB0, 0x81, 0xE3, 0xA5, 0x3E, 0x93, 0x18 },
		.key_hash = { 0x17, 0xFB, 0xD1, 0xD1, 0x7D, 0xAA, 0xCE, 0xA7,
			      0xA2, 0xF6, 0xDA, 0x1F, 0x22, 0x83, 0x5E, 0x86,
			      0x30, 0xE8, 0xAE, 0x8E, 0xF1, 0xA6, 0x6E, 0x8B,
			      0x79, 0x35, 0xCC, 0x6C, 0xC7, 0x62, 0x53, 0x2D },
		.msg = { 0xA4, 0xFA, 0xDC, 0x3C, 0x23, 0x2F, 0x2A, 0xBC,
			 0x8F, 0xCB, 0xB9, 0xC1, 0x11, 0xF2, 0x61, 0xE0,
			 0x3D, 0xC2, 0xFF, 0x2D, 0x57, 0x28, 0x0A, 0x42,
			 0x42, 0x93, 0x6A, 0x63, 0xE4, 0x81, 0xAF, 0xE6 },
		.sig_hash = { 0xC0, 0x27, 0xD2, 0x1B, 0x21, 0xFA, 0x75, 0xAB,
			      0xE7, 0xF3, 0x5C, 0xD8, 0x4A, 0x54, 0xE2, 0xE8,
			      0x3B, 0xD3, 0x52, 0x14, 0x0B, 0xC8, 0xC4, 0x9E,
			      0xAB, 0x2C, 0x45, 0x00, 0x4E, 0x72, 0x68, 0xA7 },
	},
	{
		.seed = { 0xA8, 0xE6, 0xC0, 0x84, 0xB3, 0xAA, 0xE4, 0x69,
			  0x07, 0x24, 0x63, 0x1C, 0xAA, 0x57, 0xC1, 0x0D,
			  0xF5, 0x97, 0x3F, 0x95, 0x38, 0xD2, 0x54, 0x93,
			  0xE2, 0x64, 0xA4, 0xE2, 0xB2, 0xC5, 0xA4, 0xE9 },
		.key_hash = { 0xD8, 0xB7, 0xDE, 0x2D, 0xA3, 0x26, 0xEB, 0xAE,
			      0x24, 0x1D, 0x65, 0x7E, 0xC0, 0x90, 0xF4, 0xCA,
			      0x34, 0x38, 0xDF, 0xFE, 0xEC, 0xE1, 0xBD, 0x05,
			      0xD9, 0xCE, 0x7D, 0xFC, 0x52, 0x04, 0xC6, 0xDC },
		.msg = { 0xA4, 0x5A, 0x91, 0xB6, 0xB2, 0xB3, 0x92, 0xB7,
			 0x08, 0x71, 0x52, 0xD2, 0x3E, 0x57, 0xE3, 0x9A,
			 0xA7, 0x8A, 0x42, 0xAB, 0x91, 0xAA, 0xD0, 0x34,
			 0x4F, 0xB8, 0x03, 0x93, 0xF2, 0x2F, 0xB0, 0xAE },
		.sig_hash = { 0xC9, 0xDB, 0x2B, 0x64, 0x2F, 0x73, 0x9B, 0x32,
			      0xED, 0x5B, 0x14, 0xB8, 0xFE, 0xEE, 0x6C, 0x77,
			      0x9B, 0xAE, 0x72, 0x97, 0x17, 0xD4, 0xFF, 0x11,
			      0xCA, 0x28, 0x19, 0x54, 0xD8, 0xFF, 0x1B, 0x1D },
	},
	{
		/* Data from Table 2 */
		.seed = { 0x11, 0x1B, 0xDF, 0xD1, 0x3C, 0xF3, 0x0B, 0x4A,
			  0x05, 0xF8, 0xC5, 0x6E, 0x91, 0xE2, 0x00, 0x25,
			  0xB2, 0x84, 0xEF, 0xDC, 0x66, 0x1C, 0x34, 0x9D,
			  0x43, 0x0F, 0xB9, 0x88, 0x14, 0x92, 0x19, 0xEE },
		.key_hash = { 0xC0, 0x6F, 0xE4, 0x57, 0x14, 0x69, 0x6F, 0xF2,
			      0xC7, 0x7B, 0xB4, 0xCD, 0x96, 0xE7, 0x0B, 0xE9,
			      0x53, 0x91, 0x17, 0xAC, 0x3D, 0x2E, 0x3F, 0x77,
			      0xC7, 0x36, 0xB0, 0x60, 0x8D, 0x9E, 0x78, 0xB6 },
		.msg = { 0xA3, 0x09, 0x75, 0xC7, 0xC5, 0x8A, 0xBC, 0x8F,
			 0xE7, 0xFA, 0xE4, 0x42, 0xFE, 0x20, 0xF9, 0x64,
			 0x41, 0x0B, 0x74, 0xE9, 0xB4, 0xC1, 0xD4, 0x7E,
			 0x44, 0x02, 0x23, 0xC5, 0xA4, 0x6D, 0xA7, 0x2C },
		.sig_hash = { 0xCA, 0xDA, 0x29, 0xAE, 0xEC, 0x8E, 0x59, 0xCD,
			      0x70, 0x74, 0x7C, 0x2E, 0x4C, 0x83, 0xF9, 0x63,
			      0x7E, 0x3C, 0x24, 0x95, 0x3F, 0x11, 0xAD, 0xEE,
			      0xF5, 0x86, 0xF7, 0x86, 0x35, 0xB3, 0xE6, 0x0A },
	},
	{
		.seed = { 0xF3, 0xA3, 0xF2, 0xC3, 0x26, 0x3A, 0x70, 0x42,
			  0x95, 0xE9, 0xD9, 0xF7, 0x3C, 0xD9, 0x7D, 0x02,
			  0xF4, 0x68, 0x2B, 0xEE, 0x59, 0x49, 0xC4, 0x16,
			  0xBC, 0x42, 0xC8, 0x5B, 0x7C, 0x86, 0x44, 0x46 },
		.key_hash = { 0x99, 0x7C, 0xEE, 0x99, 0x5E, 0xEC, 0xE2, 0x52,
			      0x81, 0x55, 0xE1, 0xAE, 0x00, 0x95, 0x11, 0x6C,
			      0x6D, 0x97, 0xB1, 0x50, 0x8B, 0x76, 0xAD, 0x25,
			      0xBA, 0xE4, 0xAD, 0xF6, 0xB6, 0x0A, 0xE6, 0xA2 },
		.msg = { 0x1C, 0x00, 0xF3, 0xE4, 0xCF, 0x07, 0xBD, 0x4F,
			 0xB7, 0x97, 0xD6, 0x83, 0x76, 0xEE, 0xC5, 0x37,
			 0x01, 0x73, 0x0C, 0x49, 0x09, 0xEC, 0x40, 0x4F,
			 0xC9, 0x3A, 0x6B, 0x7F, 0x59, 0x7F, 0x81, 0xB5 },
		.sig_hash = { 0x00, 0x6B, 0x20, 0x5B, 0xFA, 0x8D, 0xFF, 0x6C,
			      0x2A, 0xA4, 0x23, 0x7A, 0x6B, 0xB5, 0xA3, 0x3D,
			      0xBD, 0x1B, 0x3D, 0x97, 0x13, 0xB9, 0x9A, 0x9D,
			      0x5A, 0xF9, 0xA8, 0x82, 0xCD, 0x0B, 0xA1, 0xE0 },
	}
};

#ifdef __cplusplus
}
#endif

#endif /* DILITHIUM_REJECTION_UPSTREAM_VECTORS_65_H */
