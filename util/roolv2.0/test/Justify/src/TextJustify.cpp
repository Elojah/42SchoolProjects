#include "TextJustify.hpp"
#include <stdlib.h>

// Separateur voulus (1+ possible)
#define IS_SEP(n) ((n) == ' ' || (n) == '\n' || (n) == '\t')

CTextJustify::CTextJustify(void) :
	m_tabInfoMot(NULL),
	m_bRewriteTxt(TRUE)
{
}
CTextJustify::~CTextJustify(void)
{
	_resetTab();
}
BOOL	CTextJustify::bJustifie(int nLargeurLigne, int nHauteurLigne)
{
	if (nLargeurLigne < 1)
		return (FALSE);

	// On garantit un loop unswitching en mettant un bool const
	// Optimisation compilo
	const BOOL	bRewriteTxt = m_bRewriteTxt;
	int			nCurrentWidth = 0;
	int			nCurrentLine = 0;

	m_nHauteurLigne = nHauteurLigne;
	m_nLargeurLigne = nLargeurLigne;
	for (int i = 0; i < m_nWords; ++i)
	{
		if (bRewriteTxt)
			_setNextWordStr(i);
		_setNextWordPosition(i, nCurrentWidth, nCurrentLine);
		// Si on ne dépasse pas la ligne avec le nouveau mot
		if (nCurrentWidth + m_tabInfoMot[i].nLargeur < m_nLargeurLigne)
		{
			nCurrentWidth += m_tabInfoMot[i].nLargeur;
			// On checke si on peut ajouter un espace après le mot
			if (nCurrentWidth + m_nSepSize <= m_nLargeurLigne)
				nCurrentWidth += m_nSepSize;
			// Sinon on va directement à la ligne suivante
			else
			{
				// On ajouter le petit surplus au dernier mot
				// Ca peut devenir gênant si l'espace est grand
				// Dans ce cas là, appeller _bCompenseLigne
				m_tabInfoMot[i].nX += m_nLargeurLigne - nCurrentWidth;
				++nCurrentLine;
				nCurrentWidth = 0;
			}
		}
		else
		{
			// On deborde de la ligne donc:
			// 1- On modifie le precedent mot ajoute
			_setNextWordPosition(i, 0, nCurrentLine + 1);
			// 2- On compense la derniere ligne
			_bCompenseLigne(i - 1, nCurrentWidth, nCurrentLine);
			// 3- On update les valeurs courantes
			++nCurrentLine;
			nCurrentWidth = m_tabInfoMot[i].nLargeur + m_nSepSize;
		}
	}
	m_bRewriteTxt = FALSE;
	return (TRUE);
}
BOOL	CTextJustify::bJustifie(PCXSTR pszTxt, ITailleMots *piTm, int nLargeurLigne, int nHauteurLigne)
{
	if (pszTxt == NULL || piTm == NULL)
		return (FALSE);
	// On (re)init m_tabInfoMot pour un array propre
	_resetTab();
	m_nWords = _nCountWords(pszTxt);
	m_tabInfoMot = new STInfoMot[m_nWords];
	m_pszTxt = pszTxt;
	m_piTm = piTm;
	m_nSepSize = m_piTm->nGetTailleMot((char *)" ");
	m_bRewriteTxt = TRUE;
	return (bJustifie(nLargeurLigne, nHauteurLigne));
}
void	CTextJustify::accept(IVisiteurJustifier *piVisiteur) const
{
	for (int i = 0; i < m_nWords; ++i)
		piVisiteur->bVisit(&m_tabInfoMot[i]);
}
void		CTextJustify::_setNextWordStr(int nIndex)
{
	int	i;

	while (IS_SEP(*m_pszTxt))
		++m_pszTxt;
	for (i = 0; !IS_SEP(m_pszTxt[i]) && m_pszTxt[i] != '\0'; ++i)
		;
	// On effectue la copie du mot ici
	// - Dynamic-------------------------------
	// m_tabInfoMot[nIndex].pszMot = (char *)XMALLOC((i + 1) * sizeof(char));
	// for (i = 0; !IS_SEP(m_pszTxt[i]) && m_pszTxt[i] != '\0'; ++i)
	// 	m_tabInfoMot[nIndex].pszMot[i] = m_pszTxt[i];
	// m_tabInfoMot[nIndex].pszMot[i] = '\0';
	// - Static-------------------------------
	m_pszTxt[i] = '\0';
	m_tabInfoMot[nIndex].pszMot = m_pszTxt;

	m_tabInfoMot[nIndex].nLargeur = m_piTm->nGetTailleMot(m_tabInfoMot[nIndex].pszMot);
	m_pszTxt += i + 1;
}
void		CTextJustify::_setNextWordPosition(int nIndex, int nWidth, int nLine)
{
	m_tabInfoMot[nIndex].nX = nWidth;
	m_tabInfoMot[nIndex].nY = nLine * m_nHauteurLigne;
}
// Compte le nombre de mots dans la PCXSTR
int		CTextJustify::_nCountWords(PCXSTR const pszTxt)
{
	if (pszTxt[0] == '\0')
		return (0);

	BOOL		bSep_state;
	int			nRes = 0;

	// Utilisation d'un etat "separateur" pour sauvegarder et tick aux changements d'etat
	bSep_state = TRUE;
	for (int i = 0; pszTxt[i] != '\0'; ++i)
	{
		if ((bSep_state && IS_SEP(pszTxt[i])) || (!bSep_state && !IS_SEP(pszTxt[i])))
			continue ;
		bSep_state = !bSep_state;
		// On ajoute un mot a la premiere lettre rencontree
		if (!IS_SEP(pszTxt[i]))
			++nRes;
	}
	return (nRes);
}
BOOL	CTextJustify::_bCompenseLigne(int nIndex, int nWidth, int nLine)
{
	if (nIndex < 1)
		return (FALSE);

	int		nCurrentY = nLine * m_nHauteurLigne;
	int		nWordsInLine = 1;

	for (int i = nIndex; i > 0 && m_tabInfoMot[i - 1].nY == nCurrentY; --i)
		++nWordsInLine;
	// S'il n'y a qu'un seul mot dans la ligne, on laisse tel quel
	if (nWordsInLine < 2)
		return (FALSE);

	int		nOffset = (m_nLargeurLigne - nWidth) * m_nSepSize;
	int		nOffsetByGap = nOffset / (nWordsInLine - 1);
	int		nOffsetExceed = nOffset - (nOffsetByGap * (nWordsInLine - 1));
	int		nCount = 0;

	// On ajoute le + d'espaces a chaque gap
	for (int i = nIndex - nWordsInLine + 1; i <= nIndex; ++i)
		m_tabInfoMot[i].nX += nOffsetByGap * nCount++;
	// On ajoute les espaces restant disperses sur les premiers gaps
	nCount = 0;
	for (int i = nIndex - nWordsInLine + 1; i <= nIndex; ++i)
	{
		m_tabInfoMot[i].nX += m_nSepSize * nCount;
		if (nCount < nOffsetExceed)
			++nCount;
	}
	return (TRUE);
}
void	CTextJustify::_resetTab(void)
{
	if (m_tabInfoMot == NULL)
		return ;
	// for (int i = 0; i < m_nWords; ++i)
	// 	free(m_tabInfoMot[i].pszMot);
	delete [] m_tabInfoMot;
}
#include <iostream>
void	CTextJustify::__display(void)
{
	int		offset_y = 0;
	int		offset_x = m_nLargeurLigne;

	for (int i = 0; i < m_nWords; ++i)
	{
		if (offset_y != m_tabInfoMot[i].nY)
			std::cout << '\n';
		offset_y = m_tabInfoMot[i].nY;
		if (m_tabInfoMot[i].nX >= offset_x)
		{
			for (int j = m_tabInfoMot[i].nX - offset_x; j >= 0; --j)
				std::cout << ' ';
		}
		std::cout << m_tabInfoMot[i].pszMot;
		offset_x = m_tabInfoMot[i].nX + m_tabInfoMot[i].nLargeur + m_nSepSize;
	}
}
