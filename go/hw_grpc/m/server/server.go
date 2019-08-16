package server

import (
	"context"

	mpb "gitlab.com/OGLinuk/mdas/proto/m"
)

type Server struct{}

func (s *Server) Multiply(ctx context.Context, req *mpb.MultiplyRequest) (*mpb.MultiplyResponse, error) {
	a, b := req.GetA(), req.GetB()

	result := a * b

	return &mpb.MultiplyResponse{N: result}, nil
}
