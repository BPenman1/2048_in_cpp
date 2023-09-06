#include "cMain.h"
#include "2048.h"
#define _CRT_SECURE_NO_WARNINGS

int grid_matrix[4][4];


wxBEGIN_EVENT_TABLE(cMain, wxFrame)

//up
EVT_BUTTON(10002, on_up_clicked)

//down
EVT_BUTTON(10000, on_down_clicked)

//left
EVT_BUTTON(10001, on_left_clicked)

//right
EVT_BUTTON(10003, on_right_clicked)

//new game
EVT_BUTTON(10005, new_game)

//quit game
EVT_BUTTON(10006, quit_game)

//ask robot
EVT_BUTTON(9998, robot)

wxEND_EVENT_TABLE()

//constructor
cMain::cMain() : wxFrame(nullptr, wxID_ANY, "2048 by Brandon Penman", wxPoint(500, 500), wxSize(240,390+150))
{
	//center = 152, 260
	//control buttons
	m_btn_w = new wxButton(this, 10002, "^", wxPoint({ 152 + 8 - (25 / 4) }, { 260 - 30 + (25 / 2) }), wxSize(25, 25));
	m_btn_s = new wxButton(this, 10000, "v", wxPoint({ 152 + 8 - (25 / 4) }, { 260 + 30 + (25 / 2) }), wxSize(25, 25));
	m_btn_a = new wxButton(this, 10001, "<", wxPoint({ 152 - 30 + 8 - (25 / 4) }, { 260 + (25 / 2) }), wxSize(25, 25));
	m_btn_d = new wxButton(this, 10003, ">", wxPoint({ 152 + 30 + 8 - (25 / 4) }, { 260 + (25 / 2) }), wxSize(25, 25));

	//new game and quit game
	m_btn_new = new wxButton(this, 10005, "New Game", wxPoint(10, 230), wxSize(100, 50));
	m_btn_quit = new wxButton(this, 10006, "Quit", wxPoint(10, 286), wxSize(100, 50));

	//robot button
	m_btn_robot = new wxButton(this, 9998, "Random Direction", wxPoint(10, 343), wxSize(200, 50));

	//input text box
	text_box = new wxListBox(this, 1111, wxPoint(10, 403), wxSize(200, 85));




	//grid
	m_btn_0_0 = new wxButton(this, 9900, "", wxPoint(10, 10), wxSize(50, 50));
	m_btn_1_0 = new wxButton(this, 9910, "", wxPoint(62, 10), wxSize(50, 50));
	m_btn_2_0 = new wxButton(this, 9920, "", wxPoint(114, 10), wxSize(50, 50));
	m_btn_3_0 = new wxButton(this, 9930, "", wxPoint(166, 10), wxSize(50, 50));

	m_btn_0_1 = new wxButton(this, 9901, "", wxPoint(10, 62), wxSize(50, 50));
	m_btn_1_1 = new wxButton(this, 9911, "", wxPoint(62, 62), wxSize(50, 50));
	m_btn_2_1 = new wxButton(this, 9921, "", wxPoint(114, 62), wxSize(50, 50));
	m_btn_3_1 = new wxButton(this, 9931, "", wxPoint(166, 62), wxSize(50, 50));

	m_btn_0_2 = new wxButton(this, 9902, "", wxPoint(10, 114), wxSize(50, 50));
	m_btn_1_2 = new wxButton(this, 9912, "", wxPoint(62, 114), wxSize(50, 50));
	m_btn_2_2 = new wxButton(this, 9922, "", wxPoint(114, 114), wxSize(50, 50));
	m_btn_3_2 = new wxButton(this, 9932, "", wxPoint(166, 114), wxSize(50, 50));

	m_btn_0_3 = new wxButton(this, 9903, "", wxPoint(10, 166), wxSize(50, 50));
	m_btn_1_3 = new wxButton(this, 9913, "", wxPoint(62, 166), wxSize(50, 50));
	m_btn_2_3 = new wxButton(this, 9923, "", wxPoint(114, 166), wxSize(50, 50));
	m_btn_3_3 = new wxButton(this, 9933, "", wxPoint(166, 166), wxSize(50, 50));


	//seed for randoom number generation uses system clock
	srand(time(NULL));

	//manually sets new game
	clear_game();
	print_grid();

	//color personalization


	m_btn_new->SetBackgroundColour(wxColour(63,133,176));
	m_btn_new->SetForegroundColour(wxColour(255,255,255));

	m_btn_quit->SetBackgroundColour(wxColour(63, 133, 176));
	m_btn_quit->SetForegroundColour(wxColour(255, 255, 255));

	m_btn_robot->SetBackgroundColour(wxColour(63, 133, 176));
	m_btn_robot->SetForegroundColour(wxColour(255, 255, 255));

	m_btn_w->SetBackgroundColour(wxColour(63, 133, 176));
	m_btn_w->SetForegroundColour(wxColour(255, 255, 255));

	m_btn_a->SetBackgroundColour(wxColour(63, 133, 176));
	m_btn_a->SetForegroundColour(wxColour(255, 255, 255));

	m_btn_s->SetBackgroundColour(wxColour(63, 133, 176));
	m_btn_s->SetForegroundColour(wxColour(255, 255, 255));

	m_btn_d->SetBackgroundColour(wxColour(63, 133, 176));
	m_btn_d->SetForegroundColour(wxColour(255, 255, 255));

	text_box->SetBackgroundColour(wxColour(32, 67, 89));
	text_box->SetForegroundColour(wxColour(255, 255, 255));
}

//deconstructor
cMain::~cMain() {
	Destroy();
}

//functions

void cMain::on_down_clicked(wxCommandEvent& evt) {
	commands(1);
	print_grid();

	//update list box
	wxString down = "Down";
	cMain::text_box->Insert(down,0);

	evt.Skip();
}

void cMain::on_up_clicked(wxCommandEvent& evt) {
	commands(3);
	print_grid();
	
	//update list box
	wxString up = "Up";
	cMain::text_box->Insert(up,0);

	evt.Skip();
}

void cMain::on_left_clicked(wxCommandEvent& evt) {
	commands(2);
	print_grid();

	//update list box
	wxString left = "Left";
	cMain::text_box->Insert(left,0);

	evt.Skip();
}

void cMain::on_right_clicked(wxCommandEvent& evt) {
	commands(0);
	print_grid();

	//update list box
	wxString right = "Right";
	cMain::text_box->Insert(right,0);

	evt.Skip();
}

void cMain::new_game(wxCommandEvent& evt) {
	clear_game();
	print_grid();
	evt.Skip();
}

void cMain::quit_game(wxCommandEvent& evt) {
	commands(99);
	evt.Skip();
}

void cMain::robot(wxCommandEvent& evt) {
	commands(find_best_move());
	print_grid();
	evt.Skip();
}

//************************************************Start of original 2048 Console Code*******************************************************************



//tests if a move has been made to determine whether to add another piece
bool move_made(int before[4][4], int after[4][4]) {
	int true_false = 1;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (before[i][j] != after[i][j]) {
				true_false = 0;
			}
		}
	}

	if (true_false == 0){
		return true;
	}
	else {
		return false;
	}
}

//generate values for an open position
std::pair<int, int> cMain::gen_open_pos() {
	int occupied = 1, row, column;
	while (occupied == 1) {
		//selects random position on grid
		row = rand() % 4;
		column = rand() % 4;

		//tests if space specified by rand is empty
		if (grid_matrix[row][column] == 0) {
			occupied = 0;
		}
	}
	return std::make_pair(row, column);
}

//add piece after move
void cMain::add_tile() {
	int tile_value = rand() % 10;
	if (tile_value <= 9) {
		std::pair<int, int> pos2 = gen_open_pos();
		grid_matrix[pos2.first][pos2.second] = 2;
	}
	else if (tile_value > 9) {
		std::pair<int, int> pos2 = gen_open_pos();
		grid_matrix[pos2.first][pos2.second] = 4;
	}
}

//clears game
void cMain::clear_game() {
	//writes 0s across entire grid
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			grid_matrix[i][j] = 0;

		}
	}
	//adds two 2s in random locations
	std::pair<int, int> pos1 = gen_open_pos();
	grid_matrix[pos1.first][pos1.second] = 2;

	std::pair<int, int> pos2 = gen_open_pos();
	grid_matrix[pos2.first][pos2.second] = 2;

}

//prints values to GUI
void cMain::print_grid() {
	wxString none = " ";
				//************************************************************************************************
			//changes zero to space
			if (grid_matrix[0][0] == 0) {
				cMain::m_btn_0_0->SetLabel(none);
			}
			else {
				int var = grid_matrix[0][0];
				wxString value = wxString::Format(wxT("%i"), var);
				cMain::m_btn_0_0->SetLabel(value);
			}

				if (grid_matrix[1][0] == 0) {
					cMain::m_btn_1_0->SetLabel(none);
				}
				else {
					int var = grid_matrix[1][0];
					wxString value = wxString::Format(wxT("%i"), var);
					cMain::m_btn_1_0->SetLabel(value);
				}

				if (grid_matrix[2][0] == 0) {
					cMain::m_btn_2_0->SetLabel(none);
				}
				else {
					int var = grid_matrix[2][0];
					wxString value = wxString::Format(wxT("%i"), var);
					cMain::m_btn_2_0->SetLabel(value);
				}

				if (grid_matrix[3][0] == 0) {
					cMain::m_btn_3_0->SetLabel(none);
				}
				else {
					int var = grid_matrix[3][0];
					wxString value = wxString::Format(wxT("%i"), var);
					cMain::m_btn_3_0->SetLabel(value);
				}

				//**********************************************************************************************

			if (grid_matrix[0][1] == 0) {
				cMain::m_btn_0_1->SetLabel(none);
			}
			else {
				int var = grid_matrix[0][1];
				wxString value = wxString::Format(wxT("%i"), var);
				cMain::m_btn_0_1->SetLabel(value);
			}

				if (grid_matrix[1][1] == 0) {
					cMain::m_btn_1_1->SetLabel(none);
				}
				else {
					int var = grid_matrix[1][1];
					wxString value = wxString::Format(wxT("%i"), var);
					cMain::m_btn_1_1->SetLabel(value);
				}

				if (grid_matrix[2][1] == 0) {
					cMain::m_btn_2_1->SetLabel(none);
				}
				else {
					int var = grid_matrix[2][1];
					wxString value = wxString::Format(wxT("%i"), var);
					cMain::m_btn_2_1->SetLabel(value);
				}

				if (grid_matrix[3][1] == 0) {
					cMain::m_btn_3_1->SetLabel(none);
				}
				else {
					int var = grid_matrix[3][1];
					wxString value = wxString::Format(wxT("%i"), var);
					cMain::m_btn_3_1->SetLabel(value);
				}

				//**********************************************************************************************************

			if (grid_matrix[0][2] == 0) {
				cMain::m_btn_0_2->SetLabel(none);
			}
			else {
				int var = grid_matrix[0][2];
				wxString value = wxString::Format(wxT("%i"), var);
				cMain::m_btn_0_2->SetLabel(value);
			}

				if (grid_matrix[1][2] == 0) {
					cMain::m_btn_1_2->SetLabel(none);
				}
				else {
					int var = grid_matrix[1][2];
					wxString value = wxString::Format(wxT("%i"), var);
					cMain::m_btn_1_2->SetLabel(value);
				}

				if (grid_matrix[2][2] == 0) {
					cMain::m_btn_2_2->SetLabel(none);
				}
				else {
					int var = grid_matrix[2][2];
					wxString value = wxString::Format(wxT("%i"), var);
					cMain::m_btn_2_2->SetLabel(value);
				}

				if (grid_matrix[3][2] == 0) {
					cMain::m_btn_3_2->SetLabel(none);
				}
				else {
					int var = grid_matrix[3][2];
					wxString value = wxString::Format(wxT("%i"), var);
					cMain::m_btn_3_2->SetLabel(value);
				}

				//***************************************************************************************************************

			if (grid_matrix[0][3] == 0) {
				cMain::m_btn_0_3->SetLabel(none);
			}
			else {
				int var = grid_matrix[0][3];
				wxString value = wxString::Format(wxT("%i"), var);
				cMain::m_btn_0_3->SetLabel(value);
			}

				if (grid_matrix[1][3] == 0) {
					cMain::m_btn_1_3->SetLabel(none);
				}
				else {
					int var = grid_matrix[1][3];
					wxString value = wxString::Format(wxT("%i"), var);
					cMain::m_btn_1_3->SetLabel(value);
				}

				if (grid_matrix[2][3] == 0) {
					cMain::m_btn_2_3->SetLabel(none);
				}
				else {
					int var = grid_matrix[2][3];
					wxString value = wxString::Format(wxT("%i"), var);
					cMain::m_btn_2_3->SetLabel(value);
				}

				if (grid_matrix[3][3] == 0) {
					cMain::m_btn_3_3->SetLabel(none);
				}
				else {
					int var = grid_matrix[3][3];
					wxString value = wxString::Format(wxT("%i"), var);
					cMain::m_btn_3_3->SetLabel(value);
				}


	//controls grid colors
	if (grid_matrix[0][0]>0){
		int color = 209 - (log2 (grid_matrix[0][0]))*11;
		m_btn_0_0->SetBackgroundColour(wxColour(color, 230, 255));
	}
	else {
		m_btn_0_0->SetBackgroundColour(wxColour(240, 240, 255));
	}

	if (grid_matrix[0][1] > 0) {
		int color = 209 - (log2(grid_matrix[0][1])) * 11;
		m_btn_0_1->SetBackgroundColour(wxColour(color, 230, 255));
	}
	else {
		m_btn_0_1->SetBackgroundColour(wxColour(240, 240, 255));
	}

	if (grid_matrix[0][2] > 0) {
		int color = 209 - (log2(grid_matrix[0][2])) * 11;
		m_btn_0_2->SetBackgroundColour(wxColour(color, 230, 255));
	}
	else {
		m_btn_0_2->SetBackgroundColour(wxColour(240, 240, 255));
	}

	if (grid_matrix[0][3] > 0) {
		int color = 209 - (log2(grid_matrix[0][3])) * 11;
		m_btn_0_3->SetBackgroundColour(wxColour(color, 230, 255));
	}
	else {
		m_btn_0_3->SetBackgroundColour(wxColour(240, 240, 255));
	}

	////////////////////////////////
	if (grid_matrix[1][0] > 0) {
		int color = 209 - (log2(grid_matrix[1][0])) * 11;
		m_btn_1_0->SetBackgroundColour(wxColour(color, 230, 255));
	}
	else {
		m_btn_1_0->SetBackgroundColour(wxColour(240, 240, 255));
	}

	if (grid_matrix[1][1] > 0) {
		int color = 209 - (log2(grid_matrix[1][1])) * 11;
		m_btn_1_1->SetBackgroundColour(wxColour(color, 230, 255));
	}
	else {
		m_btn_1_1->SetBackgroundColour(wxColour(240, 240, 255));
	}

	if (grid_matrix[1][2] > 0) {
		int color = 209 - (log2(grid_matrix[1][2])) * 11;
		m_btn_1_2->SetBackgroundColour(wxColour(color, 230, 255));
	}
	else {
		m_btn_1_2->SetBackgroundColour(wxColour(240, 240, 255));
	}

	if (grid_matrix[1][3] > 0) {
		int color = 209 - (log2(grid_matrix[1][3])) * 11;
		m_btn_1_3->SetBackgroundColour(wxColour(color, 230, 255));
	}
	else {
		m_btn_1_3->SetBackgroundColour(wxColour(240, 240, 255));
	}

	////////////////
	if (grid_matrix[2][0] > 0) {
		int color = 209 - (log2(grid_matrix[2][0])) * 11;
		m_btn_2_0->SetBackgroundColour(wxColour(color, 230, 255));
	}
	else {
		m_btn_2_0->SetBackgroundColour(wxColour(240, 240, 255));
	}

	if (grid_matrix[2][1] > 0) {
		int color = 209 - (log2(grid_matrix[2][1])) * 11;
		m_btn_2_1->SetBackgroundColour(wxColour(color, 230, 255));
	}
	else {
		m_btn_2_1->SetBackgroundColour(wxColour(240, 240, 255));
	}

	if (grid_matrix[2][2] > 0) {
		int color = 209 - (log2(grid_matrix[2][2])) * 11;
		m_btn_2_2->SetBackgroundColour(wxColour(color, 230, 255));
	}
	else {
		m_btn_2_2->SetBackgroundColour(wxColour(240, 240, 255));
	}

	if (grid_matrix[2][3] > 0) {
		int color = 209 - (log2(grid_matrix[2][3])) * 11;
		m_btn_2_3->SetBackgroundColour(wxColour(color, 230, 255));
	}
	else {
		m_btn_2_3->SetBackgroundColour(wxColour(240, 240, 255));
	}

	///////////////////////
	if (grid_matrix[3][0] > 0) {
		int color = 209 - (log2(grid_matrix[3][0])) * 11;
		m_btn_3_0->SetBackgroundColour(wxColour(color, 230, 255));
	}
	else {
		m_btn_3_0->SetBackgroundColour(wxColour(240, 240, 255));
	}
	
	if (grid_matrix[3][1] > 0) {
		int color1 = 209 - (log2(grid_matrix[3][1])) * 11;
		cMain::m_btn_3_1->SetBackgroundColour(wxColour(color1, 230, 255));
	}
	else {
		cMain::m_btn_3_1->SetBackgroundColour(wxColour(240, 240, 255));
	}

	if (grid_matrix[3][2] > 0) {
		int color = 209 - (log2(grid_matrix[3][2])) * 11;
		m_btn_3_2->SetBackgroundColour(wxColour(color, 230, 255));
	}
	else {
		m_btn_3_2->SetBackgroundColour(wxColour(240, 240, 255));
	}

	if (grid_matrix[3][3] > 0) {
		int color = 209 - (log2(grid_matrix[3][3])) * 11;
		m_btn_3_3->SetBackgroundColour(wxColour(color, 230, 255));
	}
	else {
		m_btn_3_3->SetBackgroundColour(wxColour(240, 240, 255));
	}

	win_lose_condition();
}

//moves the values within the matrix
void cMain::move_numbers(int dir) {
	switch (dir) {
	case 2:
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				if (!grid_matrix[j][i])
				{
					for (int k = j + 1; k < 4; k++)
						if (grid_matrix[k][i])
						{
							grid_matrix[j][i] = grid_matrix[k][i];
							grid_matrix[k][i] = 0;
							break;
						}
				}

			}break;

	case 0:
		for (int i = 0; i < 4; i++)
			for (int j = 3; j >= 0; j--)
			{
				if (!grid_matrix[j][i])
				{
					for (int k = j - 1; k >= 0; k--)
						if (grid_matrix[k][i])
						{
							grid_matrix[j][i] = grid_matrix[k][i];
							grid_matrix[k][i] = 0;
							break;
						}
				}

			}break;
	case 3:
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				if (!grid_matrix[i][j])
				{
					for (int k = j + 1; k < 4; k++)
						if (grid_matrix[i][k])
						{
							grid_matrix[i][j] = grid_matrix[i][k];
							grid_matrix[i][k] = 0;
							break;
						}
				}

			}break;
	case 1:
		for (int i = 0; i < 4; i++)
			for (int j = 3; j >= 0; j--)
			{
				if (!grid_matrix[i][j])
				{
					for (int k = j - 1; k >= 0; k--)
						if (grid_matrix[i][k])
						{
							grid_matrix[i][j] = grid_matrix[i][k];
							grid_matrix[i][k] = 0;
							break;
						}
				}

			}break;

	}
}

//commits whatever move is entered by user
void cMain::commit_move(int dir) {

	int before_grid[4][4];
	int after_grid[4][4];

	//records state of grid before moves
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			before_grid[i][j] = grid_matrix[i][j];
		}
	}


	//move numbers operation
	move_numbers(dir);
	

	//combine numbers operation
	switch (dir) {
		//up
	case 2:
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 3; j++)
			{
				if (grid_matrix[j][i] && grid_matrix[j][i] == grid_matrix[j + 1][i])
				{
					grid_matrix[j][i] += grid_matrix[j + 1][i];
					grid_matrix[j + 1][i] = 0;

				}
			}break;
		//down
	case 0:
		for (int i = 0; i < 4; i++)
			for (int j = 3; j > 0; j--)
			{
				if (grid_matrix[j][i] && grid_matrix[j][i] == grid_matrix[j - 1][i])
				{
					grid_matrix[j][i] += grid_matrix[j - 1][i];
					grid_matrix[j - 1][i] = 0;
				}
			}break;
		//left
	case 3:
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 3; j++)
			{
				if (grid_matrix[i][j] && grid_matrix[i][j] == grid_matrix[i][j + 1])
				{
					grid_matrix[i][j] += grid_matrix[i][j + 1];
					grid_matrix[i][j + 1] = 0;
				}
			}break;
		//right
	case 1:
		for (int i = 0; i < 4; i++)
			for (int j = 3; j > 0; j--)
			{
				if (grid_matrix[i][j] && grid_matrix[i][j] == grid_matrix[i][j - 1])
				{
					grid_matrix[i][j] += grid_matrix[i][j - 1];
					grid_matrix[i][j - 1] = 0;
				}
			}
		break;
	}

	//move numbers again
	move_numbers(dir);


	//records state of grid after moves
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			after_grid[i][j] = grid_matrix[i][j];
		}
	}

	//adds tile if move was made
	if (move_made(before_grid, after_grid) == true) {
		add_tile();

	}


}

//handles the different commands
void cMain::commands(int input) {

	//handles different inputs
	if (input == 999) {
		clear_game();
	}
	//returns one to break loop
	else if (input == 99) {
		cMain::~cMain();
	}
	else {
		commit_move(input);
	}
}

//tests if any tiles are 2048 or higher or if all tiles are full.
void cMain::win_lose_condition() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			if (grid_matrix[i][j] >= 2048) {
				m_btn_w->SetBackgroundColour(wxColour(87, 235, 116));
				m_btn_a->SetBackgroundColour(wxColour(87, 235, 116));
				m_btn_s->SetBackgroundColour(wxColour(87, 235, 116));
				m_btn_d->SetBackgroundColour(wxColour(87, 235, 116));
			}
		}
	}
	int base_grid[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			base_grid[i][j] = grid_matrix[i][j];
		}
	}

	int lose = 1;

	commit_move(0);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (grid_matrix[i][j] != base_grid[i][j]) {
				lose = 0;
			}
		}
	}

	commit_move(1);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (grid_matrix[i][j] != base_grid[i][j]) {
				lose = 0;
			}
		}
	}

	commit_move(2);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (grid_matrix[i][j] != base_grid[i][j]) {
				lose = 0;
			}
		}
	}

	commit_move(3);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (grid_matrix[i][j] != base_grid[i][j]) {
				lose = 0;
			}
		}
	}

	if (lose == 1) {
		m_btn_0_0->SetBackgroundColour(*wxRED);
		m_btn_0_1->SetBackgroundColour(*wxRED);
		m_btn_0_2->SetBackgroundColour(*wxRED);
		m_btn_0_3->SetBackgroundColour(*wxRED);

		m_btn_1_0->SetBackgroundColour(*wxRED);
		m_btn_1_1->SetBackgroundColour(*wxRED);
		m_btn_1_2->SetBackgroundColour(*wxRED);
		m_btn_1_3->SetBackgroundColour(*wxRED);

		m_btn_2_0->SetBackgroundColour(*wxRED);
		m_btn_2_1->SetBackgroundColour(*wxRED);
		m_btn_2_2->SetBackgroundColour(*wxRED);
		m_btn_2_3->SetBackgroundColour(*wxRED);

		m_btn_3_0->SetBackgroundColour(*wxRED);
		m_btn_3_1->SetBackgroundColour(*wxRED);
		m_btn_3_2->SetBackgroundColour(*wxRED);
		m_btn_3_3->SetBackgroundColour(*wxRED);

		wxString lose = "YOU LOSE";
		text_box->Insert(lose, 0);
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			grid_matrix[i][j] = base_grid[i][j];
		}
	}

}

//************************************************************************************************************************************************

int cMain::find_best_move() {
	int best_move;

	best_move = rand() % 4;

	//updates move list
	if (best_move == 0) {
		wxString right = "right";
		cMain::text_box->Insert(right,0);
	}
	else if (best_move == 1) {
		wxString down = "down";
		cMain::text_box->Insert(down,0);
	}
	else if (best_move == 2) {
		wxString left = "left";
		cMain::text_box->Insert(left,0);
	}
	else if (best_move == 3) {
		wxString up = "up";
		cMain::text_box->Insert(up,0);
	}

	return best_move;
}


/*
down=1
up=3
left=2
right=0
*/
