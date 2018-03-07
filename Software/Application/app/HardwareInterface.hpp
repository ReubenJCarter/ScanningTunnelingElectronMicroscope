#pragma once


class Hardwareinterface
{
	public:
		void Open();
		void Close();
		void CommandSetTunSetPoint(uint16_t setpoint); 
		void CommandSetTunStopPoint(uint16_t stoppoint); 
		void CommandStartZController(); 
		void CommandStopZController(); 
		void CommandMoveToZ(uint16_t z); 
		void CommandMoveToXY(uint16_t x, uint16_t y); 
		void CommandStartScan(uint16_t minX, uint16_t minY, uint16_t maxX, uint16_t maxY); 
		void CommandStopScan(); 
		void CommandSetBias(uint16_t bias); 
};