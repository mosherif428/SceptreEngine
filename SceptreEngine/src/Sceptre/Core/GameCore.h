#pragma once

#include "../../enginepch.h"
#include "../Core.h"

namespace SceptreEngine
{
	class SCEPTRE_API GameCore
	{

	public:

		//////////////////////////////////
		// custom structs and functions //

		
		struct CharPtrHash {
			std::size_t operator()(const char* str) const {
				std::size_t hash = 5381;
				while (int c = *str++) {
					hash = ((hash << 5) + hash) + c; // hash * 33 + c
				}
				return hash;
			}
		};

		struct CharPtrEqual {
			bool operator()(const char* lhs, const char* rhs) const {
				return std::strcmp(lhs, rhs) == 0;
			}
		};

		std::unordered_map<const char*, std::string, CharPtrHash, CharPtrEqual> CountryList;

		struct Color {
			uint8_t r, g, b;

			Color() : r(0), g(0), b(0) {}
			Color(uint8_t red, uint8_t green, uint8_t blue) : r(red), g(green), b(blue) {}

			bool operator==(const Color& other) const {
				return r == other.r && g == other.g && b == other.b;
			}

			uint32_t toPacked() const {
				return (r << 16) | (g << 8) | b;
			}

			static Color fromPacked(uint32_t packedColor) {
				return Color(
					(packedColor >> 16) & 0xFF,
					(packedColor >> 8) & 0xFF,
					packedColor & 0xFF
				);
			}
		};

		struct Date
		{
			int day, month, year;
		};

		// Function to check if a year is a leap year
		bool isLeapYear(int year) {
			return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		}

		// Function to get the number of days in a month for a given year
		int daysInMonth(int month, int year) {
			switch (month) {
			case 1:  return 31;
			case 2:  return isLeapYear(year) ? 29 : 28;
			case 3:  return 31;
			case 4:  return 30;
			case 5:  return 31;
			case 6:  return 30;
			case 7:  return 31;
			case 8:  return 31;
			case 9:  return 30;
			case 10: return 31;
			case 11: return 30;
			case 12: return 31;
			default: return 0; // Invalid month
			}
		}

		// Function to increment the date by one day
		void incrementDate(Date& date) {
			date.day++;
			if (date.day > daysInMonth(date.month, date.year)) {
				date.day = 1;
				date.month++;
				if (date.month > 12) {
					date.month = 1;
					date.year++;
				}
			}
		}

		//      end of custom stuff     //
		//////////////////////////////////

	public:

		class CCulture
		{

		};

		class CReligion
		{

		};

		class CTrait
		{
			// positive and negative modifiers
		};

		class CTradeGood
		{
			std::string Name;
			bool isDerived; // or a resource
		};

		class CCharacter
		{
			uint32_t CharacterID;
			std::string FirstName;
			std::string Dynasty;
			//std::string FullName = FirstName + " " + Dynasty;
			CReligion& CharReligion;
			CCulture& CharCulture;
			CTrait& CharTrait;

			// Implement DNA / appearance

			struct CharacterStats // to be revised
			{
				uint32_t Martial;
				uint32_t Administrative;
				uint32_t Diplomatic;
			};


		};

		class CCountry
		{
		private:
			char* CountryTag[3]; // Three Letter Tag
			std::string CountryName; // to be localized
			CCharacter& CountryLeader;
			CReligion& CountryReligion;
			CCulture& CountryCulture;

		public:
			bool isAI;


		// functions
		private:

		public:
			std::string getCountryNamefromTag(const std::unordered_map<const char*, std::string, CharPtrHash, CharPtrEqual>& map, const char* key);
		};

		class CPop
		{
			uint64_t PopCount;
			CReligion& PopReligion;
			CCulture& PopCulture;
			CTradeGood& PopNeed;
			CTradeGood& PopProduce;
			
		};

		class CProvince
		{
			uint32_t ProvinceID; // hex 0x000001
			Color ProvinceColor; // RGB
			CPop* Inhabitants[];

			class CBuilding
			{
				uint32_t BuildingType; // 0 = empty slot


			};
		};

		class CInteraction
		{
			// character interactions, country, province interactions
		};

		class CCharacterInteraction : public CInteraction
		{

		};

		class CGameState
		{
		public:
			Date StartDate;
			Date CurrentDate;

			enum EStateMachine
			{
				InMainMenu,
				InLoading,
				InGamePaused,
				InGameUnpaused,
				InGamePauseMenu
			};

		};




	public:

		bool IsPaused = true;
		CGameState Run();
		void Tick(CGameState gamestate);


	};
}